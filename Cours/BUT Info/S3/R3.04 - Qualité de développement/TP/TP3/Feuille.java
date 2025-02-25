package TP3;

public class Feuille implements Composite {
	Processus process;
	
	public Feuille(Processus p) {
		this.process = p;
	}

	@Override
	public Integer getPoids() {
		return this.process.getPrio();
	}

	@Override
	public Integer getValeur() {
		return this.process.getPrio();
	}

	@Override
	public boolean estVide() {
		return false;
	}

	@Override
	public boolean contient(Processus p) {
		if(this.process.getPrio() == p.getPrio()) {
			return true;
		}
		return false;
	}

	@Override
	public void afficherInfixe() {
		System.out.println("\nUne feuille, valeur : " + this.process.toString());
	}

	@Override
	public Composite inserer(Processus p) {
		if(this.process.plusPrioritaire(p)) {
			return new Maximier(this.process, new Vide(), new Feuille(p));
		} else {
			return new Maximier(p, new Feuille(this.process), new Vide());
		}
	}

	@Override
	public Composite supprimer() {
		return new Vide();
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
