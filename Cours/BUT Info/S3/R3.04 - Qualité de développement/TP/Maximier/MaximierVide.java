package TP3;

import java.util.ArrayList;

public class MaximierVide extends Maximier {

	MaximierVide() {
		
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

	@Override
	Integer getVal() {
		return null;
	}

	@Override
	ArrayList<Integer> valeursMaximier() {
		return new ArrayList<Integer>();
	}

	@Override
	Integer plusGrandeValeur() {
		return -1;
	}

}
