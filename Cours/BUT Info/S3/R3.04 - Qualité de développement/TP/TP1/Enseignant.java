package Qualite_dev;

public class Enseignant extends Personne {
	
	public Enseignant(String nom) {
		super(nom);
	}
	
	public void afficherEnseignant() {
		System.out.println(this.toString());
	}

	@Override
	public String toString() {
		return "C'est un enseignant qui s'appelle : " + this.getNom();
	}
}
