package Maximier;

public class Noeud extends Maximier {
	Maximier g;
	int val;
	Maximier d;
	
	
	public Noeud(int v, Maximier mg, Maximier md) {
		val = v;
		g = mg;
		d = md;
	}


	@Override
	int poids() {
		return 1 + g.poids() + d.poids();
	}


	@Override
	Maximier inserer(int v) {
		int a_inserer = v;
		if(val < a_inserer) {
			a_inserer = val;
			val = v;
		}
		if(g.poids() < d.poids()) {
			g = g.inserer(a_inserer);
		} else {
			d = d.inserer(a_inserer);
		}
		return this;
	}


	@Override
	boolean estVide() {
		return true;
	}


	@Override
	void afficherInf() {
		System.out.println(g);
		System.out.println(val);
		System.out.println(d);
	}


	@Override
	Maximier supprimer(int v) {
		Maximier trouve = this.rechercher(v);
		Maximier res = this;
		if(!trouve.estVide()) {
			if(trouve.g.estVide() && trouve.d.estVide()) {
				res = new MaximierVide();
			} else if(trouve.g.estVide()) {
				res = trouve.d;
			} else if(trouve.d.estVide()) {
				res = trouve.g;
			} else {
				// A faire
				trouve.d = trouve.d.inserer(v);
				res = trouve.d;
			}
		}
		
		return res;
	}


	@Override
	Maximier rechercher(int v) {
		Maximier res;
		if(val == v) {
			res = this;
		} else {
			res = g.rechercher(v);
			if(res.estVide()) {
				res = d.rechercher(v);
			}
		}
		return res;
	}

}
