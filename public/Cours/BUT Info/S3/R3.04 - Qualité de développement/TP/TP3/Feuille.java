package TP3;

public class Feuille implements Composite {
	Integer valeur;
	
	public Feuille(Integer v) {
		this.valeur = v;
	}

	@Override
	public Integer getPoids() {
		return this.getValeur();
	}

	@Override
	public Integer getValeur() {
		return this.getValeur();
	}

	@Override
	public boolean estVide() {
		return false;
	}

	@Override
	public boolean contient(Integer v) {
		if(this.getValeur() == v) {
			return true;
		}
		return false;
	}

	@Override
	public void afficherInfixe() {
		System.out.println("Une feuille, valeur : " + this.getValeur());
	}

	@Override
	public Composite inserer(Integer n) {
		Maximier m = new Maximier(this.getValeur(), new Vide(), new Feuille(n));
		return m;
	}

	@Override
	public Composite supprimerRacine() {
		return new Vide();
	}

	@Override
	public void setValeur(Integer v) {
		this.valeur = v;
	}

}
