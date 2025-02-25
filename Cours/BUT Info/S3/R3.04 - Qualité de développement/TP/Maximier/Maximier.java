package TP3;

import java.util.ArrayList;

public abstract class Maximier {
	abstract int poids();
	abstract Maximier inserer(int v); // Retourne le maximier après insertion.
	abstract boolean estVide();
	
	abstract void afficherInf();
	abstract Maximier supprimer(int v);
	abstract Maximier rechercher(int v);
	abstract Integer getVal();
	abstract ArrayList<Integer> valeursMaximier();
	abstract Integer plusGrandeValeur();
}
