package TP3;

public class Maximier implements Composite {
    private Processus process;
    private Composite gauche, droit;

   
    // Constructeur pour créer un Maximier avec une valeur donnée.
    public Maximier(Processus p, Composite vDroite, Composite vGauche) {
        this.process = p;
        this.gauche = vDroite;
        this.droit = vGauche;
    }

    // Méthode pour créer et retourner un objet Vide
    public static Composite createVide() {
        return new Vide();
    }
    
    // Obtenir la somme des valeurs de l'arbre.
    @Override
    public Integer getPoids() {
    	return this.process.getPrio() + this.gauche.getPoids() + this.droit.getPoids();
    }

    // Vérifier si l'arbre est vide.
    @Override
    public boolean estVide() {
        return this.gauche == null && this.droit == null;
    }	
    
    // Affichage de l'arbre.
    @Override
    public void afficherInfixe() {
    	System.out.print("\nNoeud : " + this.process.toString());
        this.gauche.afficherInfixe();
        this.droit.afficherInfixe();
    }
    
    // Rechercher la présence d'un élément.
    @Override
    public boolean contient(Processus p) {
    	return (this.process.plusPrioritaire(p)) && ((this.process.getPrio() == p.getPrio()) 
    			|| (this.gauche.contient(p) || (this.droit.contient(p))));
    }
    
    // Suppression de la racine.
    @Override
    public Composite supprimer() {
    	System.out.println("Suppression de : " + this.process.toString());
    	
    	if(this.process.getPrio() > this.gauche.getValeur()) {
    		this.process.setPrio(this.gauche.getValeur());
    		this.gauche = this.gauche.supprimer();
    	} else {
    		this.process.setPrio(this.droit.getValeur());
    		this.droit = this.droit.supprimer();
    	}
    	return this;
    }
    
	// Inserer une valeur.
	@Override
	public Composite inserer(Processus p) {
    	if(this.process.plusPrioritaire(p)) {
        	if(this.gauche.getPoids() < this.droit.getPoids()) {
        		this.gauche = this.gauche.inserer(p);
        	} else {
        		this.droit = this.droit.inserer(p);
        	}
    	} else {
    		Processus tmp = this.process;
    		this.process = p;
    		this.inserer(tmp);
    	}

    	return this;
	}

    // Get la valeur.
	@Override
	public Integer getValeur() {
		return this.process.getPrio();
	}

	@Override
	public void setValeur(Integer v) {
		this.process.setPrio(v);
	}

	@Override
	public Processus suivant() {
    	return this.process;
	}
	
	
}
