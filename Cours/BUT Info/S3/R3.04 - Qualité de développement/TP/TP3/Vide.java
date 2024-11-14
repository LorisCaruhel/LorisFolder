package TP3;

public class Vide implements Composite {

	public Vide() {
		
	}

	@Override
	public Integer getPoids() {
		return 0;
	}

	@Override
	public Integer getValeur() {
		return -1;
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
	public Composite inserer(Processus n) {
		return new Feuille(n);
	}

	@Override
	public Composite supprimer() {
		return new Vide();
	}

	@Override
	public void setValeur(Integer v) {
		System.out.println("Cet objet n'a pas de valeur");
	}

	@Override
	public Processus suivant() {
		return null;
	}

}
