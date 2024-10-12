package Qualite_dev;

public abstract class Personne {
	private String nom;
	
	public Personne(String nom) {
		this.setNom(nom);
	}
	
	public String toString() {
		return "Mon nom est " + this.getNom();
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}
}
