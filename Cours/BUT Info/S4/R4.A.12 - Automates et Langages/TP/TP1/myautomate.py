import numpy as np

class Automate:
    """ Cette classe représente tout type d'automate fini déterministe."""
    def __init__(self, alphabet):
        """ Initialise l'automate fini. alphabet est une chaîne de caractères"""

        """ Liste de caractères qui correspond aux états."""
        self.etats = []
        
        """ Dictionnaire dont les clefs sont les états et les valeurs des couples
        (dest_etat, symbole).
        self.transitions = {"q0": [("q1", "a"), ("q2", "b")]}
        """
        self.transitions = dict()
        
        """ état initial """
        self.initial = None
        
        """ Liste des états finaux."""
        self.finaux = []
        
        """ Liste des symboles de l'alphabet."""
        self.alphabet = ""
        for s in alphabet:
            if s not in self.alphabet:
                self.alphabet += s

    def ajoute_etat(self, etat, final = False):
        """ ajoute un nouvel etat. Envoie un message d'erreur si l'état existe déjà.
            etat   désigne le nom du nouvel état.
            final   détermine si l'état est final ou pas"""
        if final:
            if etat not in self.finaux:
                self.finaux.append(etat)
                self.etats.append(etat)
            else:
                print("Erreur l'état est déjà présent dans les états")
        else:
            if etat not in self.etats:
                self.etats.append(etat)
                if self.initial == None:
                    self.initial = etat
            else:
                print("Erreur l'état est déjà présent dans les états finaux")
        
       

    def valid_symbole(self, symbole):
        """ Retourne vrai si le symbole appartient à alphabet et faux sinon"""
        if symbole in self.alphabet:
            return True
        return False
        

    def destination_etat(self, source_etat, symbole):
        """ Recherche la transition correspondant à source_etat, symbole 
        puis retourne l'état de destination.
        Si la transition n'existe pas, retourne None. """
        res = []
        if source_etat in self.transitions:
            valeursArriver = self.transitions[source_etat]
            for tuple in valeursArriver:
                if tuple[1] == symbole:
                    res.append(tuple[0])
        else:
            print("Pas dans les transitions")
            return None
        return res

    def ajoute_transition(self, source_etat, symbole, destination_etat):
        """ ajoute une transition à l'automate. Renvoie une erreur si l'automate a déjà
            une transition depuis source_etat et symbole."""
        if source_etat in self.transitions:
            for tuple in self.transitions[source_etat]:
                if tuple[0] == destination_etat and tuple[1] == symbole:
                    print("Transition déjà existante (", source_etat, symbole, destination_etat, ")")
                    return
            self.transitions[source_etat].append((destination_etat, symbole))
        else:
            self.transitions[source_etat] = [(destination_etat, symbole)]
        
    def supprime_etat(self, etat):
        """ supprime un état. Envoie un message d'erreur si l'état n'existe pas"""
        if etat in self.etats and etat in self.transitions:
            for i in range(len(self.etats)):
                if self.etats[i] == etat:
                    self.etats.pop(i)
            self.transitions.pop(etat)
        else:
            print("Erreur l'état n'existe pas")

    def supprime_symbole(self, symbole):
        """ supprime le symbole de l'alphabet si symbole appartient à alphabet 
        et retourne un message d'erreur sinon"""
        if symbole in self.alphabet:
            arrayAlphabet = list(self.alphabet)
            indexSymbole = arrayAlphabet.index(symbole)
            arrayAlphabet.pop(indexSymbole)
            
            self.alphabet = "".join(arrayAlphabet)

            # Supprimer toutes les transitions où ce symbole apparaît
            for source_etat, transitions in self.transitions.items():
                for destination_etat, transition_symbole in transitions:
                    if transition_symbole == symbole:
                        self.supprime_transition(source_etat, transition_symbole, destination_etat)
        else:
            print("Erreur ce symbole n'est pas dans l'alphabet de cette automate")
         

    def supprime_transition(self, source_etat, symbole, destination_etat):
        """Supprime une transition de l'automate. Renvoie une erreur si la transition n'existe pas."""
        if source_etat in self.transitions:
            transition_a_supprimer = (destination_etat, symbole)
            
            if transition_a_supprimer in self.transitions[source_etat]:
                self.transitions[source_etat].remove(transition_a_supprimer)
            else:
                print(f"Erreur : La transition ({source_etat}, {symbole}, {destination_etat}) n'existe pas.")
        else:
            print(f"Erreur : L'état source '{source_etat}' n'existe pas.")

        
    def test_mot(self,mot):
        """ Vérifie si un mot est reconnu par l'automate ou pas"""
        motDecompose = list(mot)
        currentEtat = self.initial
        nbCharValid = 0

        for lettre in motDecompose:
            if lettre in self.alphabet:
                for tuple in self.transitions[currentEtat]:
                    if tuple[1] == lettre:
                        # print("Test de", lettre, "dans etat", currentEtat, "dans tuple", tuple) # DEBUG
                        currentEtat = tuple[0]
                        nbCharValid += 1
            else:
                print("Symbole", lettre, "pas dans l'alphabet")
                return False

        if nbCharValid == len(mot) and currentEtat in self.finaux:
            print("Mot", mot, "reconnue par l'automate")
            return True
        elif currentEtat not in self.finaux:
            print("Erreur : Le mot", mot,"ne s'arrete pas a un etat final", "(", currentEtat, ")")
        else: 
            print("Mot", mot, "non reconnue par l'automate")
            return False
    
    def successeurs(self, etat):
        successeurs = []
        for tuple in self.transitions[etat]:
            successeurs.append(tuple[0])
        return np.unique(successeurs)

    def predecesseurs(self, etat):
        predecesseurs = []
        for transition in self.transitions.items():
            # Garder l'état courant pour pouvoir l'ajouter dans predesseurs après
            currentEtat = transition[0]

            # Pour chaque transitions de cette état vérifier s'il y a une transition vers 
            # le currentEtat et le mettre dans le tableau si c'est le cas. 
            for tuple in transition[1]:
                if tuple[0] == etat:
                    predecesseurs.append(currentEtat)
        return np.unique(predecesseurs)
    
    def est_complet(self):
        complet = {}

        # Construction du dictionnaire des symboles présents pour chaque état
        for etat, transitions in self.transitions.items():
            if etat not in complet:
                complet[etat] = set()  # Utilisation d'un ensemble pour éviter les doublons
            for destination, symbole in transitions:
                if symbole in complet[etat]:
                    return False
                complet[etat].add(symbole)

        # Vérification que chaque état a une transition pour chaque symbole de l'alphabet
        for etat, symboles in complet.items():
            if len(symboles) != len(self.alphabet):  
                return False

        return True

    def complete(self):
        etat_puits = "P"

        if not self.est_complet():
            # Ajouter l'état puits s'il n'existe pas encore
            if etat_puits not in self.etats:
                self.ajoute_etat(etat_puits)

            # Vérifier chaque état et compléter les transitions manquantes
            for etat in self.etats:
                transitions_existantes = []
                for transition in self.transitions.get(etat, []):
                    symbole = transition[1]
                    transitions_existantes.append(symbole)

                for symbole in self.alphabet:
                    if symbole not in transitions_existantes:
                        self.ajoute_transition(etat, symbole, etat_puits)
        else:
            print("Automate déjà complet")

    def etats_accessibles(self):
        if len(self.transitions) == len(self.etats):
            return True
        return False

    def __str__(self):
        """ surcharge __str__ pour afficher les automates """
        ret = "Automate fini :\n"
        ret += "   - alphabet   : '" + self.alphabet + "'\n"
        ret += "   - état initial       : " + str(self.initial) + "\n"
        ret += "   - états finaux     : " + str(self.finaux) + "\n"
        ret += "   - nombre d'états : %d \n" % (len(self.etats))
        ret += "   - transitions :\n"
        for etat in self.etats:
            ret += "       - depuis (%s)" % (etat)
            if len(self.transitions[etat]) == 0:
                ret += ".\n"
            else:
                ret += ":\n"
                for (dest, sym) in self.transitions[etat]:
                    ret += "          --(%s)--> (%s)\n" % (sym, dest)
        return ret
    

a=Automate("ab")
a.ajoute_etat("q0")
a.initial = "q0"
a.ajoute_etat("q1")
a.ajoute_etat("q2")
a.ajoute_etat("q3")
a.ajoute_etat("q4", True)

a.ajoute_transition("q0", "b", "q0")
a.ajoute_transition("q0", "a", "q1")
a.ajoute_transition("q1", "b", "q0")
a.ajoute_transition("q1", "a", "q2")
a.ajoute_transition("q2", "a", "q2")
a.ajoute_transition("q2", "b", "q3")
a.ajoute_transition("q3", "a", "q4")
a.ajoute_transition("q3", "b", "q0")
a.ajoute_transition("q4", "a", "q4")
a.ajoute_transition("q4", "b", "q4")

a.test_mot("aaba") # Reconnue
a.test_mot("abaa") # Non reconnue
a.test_mot("bababa") # Non reconnue
a.test_mot("abaabbaaba") # Reconnue

print(a)

successeurs = a.successeurs("q0")
print("Successeurs de q0 :", successeurs)

predecesseurs = a.predecesseurs("q0")
print("Predecesseurs de q0 :", predecesseurs)

print("a est complet :", a.est_complet())
print("a est accessible :", a.etats_accessibles())


b=Automate("abc")
b.ajoute_etat("q0")
b.initial = "q0"
b.ajoute_etat("q1")
b.ajoute_etat("q2")
b.ajoute_etat("q3", True)

b.ajoute_transition("q0", "a", "q1")
b.ajoute_transition("q1", "b", "q2")
b.ajoute_transition("q2", "c", "q3")
b.ajoute_transition("q3", "a", "q3")
b.ajoute_transition("q3", "b", "q3")
b.ajoute_transition("q3", "c", "q3")

print("b est complet :", b.est_complet())

b.complete()
print(b)