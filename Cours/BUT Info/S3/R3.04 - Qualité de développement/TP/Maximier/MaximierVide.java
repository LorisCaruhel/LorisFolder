package Maximier;

public class MaximierVide extends Maximier {

	public MaximierVide() {
		
	}

	@Override
	int poids() {
		return 0;
	}

	@Override
	Maximier inserer(int v) {
		 return new Noeud(v, new MaximierVide(), new MaximierVide());
	}

	@Override
	boolean estVide() {
		return true;
	}

	@Override
	void afficherInf() {}

	@Override
	Maximier supprimer(int v) {
		return this;
	}

	@Override
	Maximier rechercher(int v) {
		return this;
	}

}
