package TP3;

public interface Composite {
	public Integer getPoids();
	public Integer getValeur();
	public void setValeur(Integer v);
	
	public boolean estVide();
	public boolean contient(Integer v);	
	
	public void afficherInfixe();
	
	public Composite inserer(Processus p);
	public Processus suivant();
	public Composite supprimer();
}
