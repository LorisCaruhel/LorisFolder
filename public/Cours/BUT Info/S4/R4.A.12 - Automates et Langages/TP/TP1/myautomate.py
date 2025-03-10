

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
            # TODO: Supprimer les transitions dans lesquelles le symbole apparaît. (avec supprime_transition)
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
            print("Erreur : Le mot ne s'arrete pas a un etat final", "(", currentEtat, ")")
        else: 
            print("Mot", mot, "non reconnue par l'automate")
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
a.test_mot("baba") # Non reconnue
a.test_mot("abaabbaaba") # Reconnue

print(a)

