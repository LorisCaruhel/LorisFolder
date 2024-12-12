package Maximier;

public abstract class Maximier {
	abstract int poids();
	abstract Maximier inserer(int v); // Retourne le maximier après insertion.
	abstract boolean estVide();
	
	abstract void afficherInf();
	abstract Maximier supprimer(int v);
	abstract Maximier rechercher(int v);
}
