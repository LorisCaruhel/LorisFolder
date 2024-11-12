package TP3;

public class Vide implements Composite {

	public Vide() {
		
	}

	@Override
	public Integer getPoids() {
		System.out.println("C'est vide.");
		return 0;
	}

	@Override
	public Integer getValeur() {
		System.out.println("C'est vide.");
		return 0;
	}

	@Override
	public boolean estVide() {
		return true;
	}

	@Override
	public boolean contient(Integer v) {
		System.out.println("C'est vide.");
		return false;
	}

	@Override
	public void afficherInfixe() {
		System.out.println("C'est vide.");
	}

	@Override
	public Composite inserer(Integer n) {
		Feuille c = new Feuille(n);
		return c;
	}

	@Override
	public Composite supprimerRacine() {
		System.out.println("C'est vide.");
		return null;
	}

	@Override
	public void setValeur(Integer v) {
		System.out.println("Cet objet n'a pas de valeur");
	}

}
