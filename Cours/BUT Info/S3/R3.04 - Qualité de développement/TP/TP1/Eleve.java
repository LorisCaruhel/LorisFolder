package Qualite_dev;

public class Eleve extends Personne {

	public Eleve(String nom) {
		super(nom);
	}

	public void afficherEnseignant() {
		System.out.println(this.toString());
	}

	@Override
	public String toString() {
		return "C'est un élève qui s'appelle : " + this.getNom();
	}
}
