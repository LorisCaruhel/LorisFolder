package TP3;

public class Maximier implements Composite {
    private Integer valeur;
    private Composite gauche, droit;

   
    // Constructeur pour créer un Maximier avec une valeur donnée.
    public Maximier(Integer v, Composite vDroite, Composite vGauche) {
        this.valeur = v;
        this.gauche = vDroite;
        this.droit = vGauche;
    }

    // Méthode pour créer et retourner un objet Vide
    public Vide createVide() {
        return new Vide(); 
    }
    
    // Obtenir la somme des valeurs de l'arbre.
    @Override
    public Integer getPoids() {
    	Integer poids = this.valeur;
        
        if (this.gauche != null) {
            poids += this.gauche.getPoids();
        }
        if (this.droit != null) {
            poids += this.droit.getPoids();
        }
        return poids;
    }

    // Vérifier si l'arbre est vide.
    @Override
    public boolean estVide() {
        return this.gauche == null && this.droit == null;
    }	
    
    // Affichage de l'arbre.
    @Override
    public void afficherInfixe() {
    	System.out.print(this.valeur + " ");
        if (this.gauche != null) {
            this.gauche.afficherInfixe();
        }
        if (this.droit != null) {
            this.droit.afficherInfixe();
        }
    }
    
    // Rechercher la présence d'un élément.
    @Override
    public boolean contient(Integer v) {
    	Boolean trouve = false;
    	
        if (this.gauche != null && !trouve) {
            if(this.gauche.getValeur() == v) {
            	trouve = true;
            }
        }
        if (this.droit != null && !trouve) {
            if(this.droit.getValeur() == v) {
            	trouve = true;
            }
        }
    	
    	return trouve;
    }
    
    // Suppression de la racine.
    @Override
    public Composite supprimerRacine() {
    	Composite c;
    	
    	if(this.valeur > this.gauche.getValeur()) {
    		c = this.gauche;
    		this.valeur = this.gauche.getValeur();
    		this.gauche.supprimerRacine();
    	} else {
    		c = this.droit;
    		this.valeur = this.droit.getValeur();
    		this.droit.supprimerRacine();
    	}
    	
    	return c;
    }
    
	// Inserer une valeur.
	@Override
	public Composite inserer(Integer n) {
    	Feuille f = new Feuille(n);
    	
    	if(this.valeur > n) {
        	if(this.gauche.getPoids() < this.droit.getPoids()) {
        		this.gauche.setValeur(n);
        	} else {
        		this.droit.setValeur(n);
        	}
    	} else {
    		int temp = this.valeur;
    		this.valeur = n;
    		this.inserer(this.valeur);
    	}

    	
    	return f;
	}

    // Get la valeur.
	@Override
	public Integer getValeur() {
		return this.valeur;
	}

	@Override
	public void setValeur(Integer v) {
		this.valeur = v;
	}
	
	
}
