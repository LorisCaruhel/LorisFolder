package TP3;

import java.util.ArrayList;
import java.util.Iterator;

public class Noeud extends Maximier {
	public Maximier d;
	public int val;
	public Maximier g;
	
	Noeud(int v, Maximier droit, Maximier gauche) {
		this.val = v;
		this.d = droit;
		this.g = gauche;
	}
	
	@Override
	int poids() {
		return 1 + g.poids() + d.poids();
	}

	@Override
	Maximier inserer(int v) {
	    if (val < v) {
	        int temp = val;
	        val = v;
	        v = temp;
	    }
	    if (g.poids() < d.poids()) {
	        g = g.inserer(v);
	    } else {
	        d = d.inserer(v);
	    }
	    return this;
	}

	@Override
	boolean estVide() {
		return false;
	}

	@Override
	void afficherInf() {
		g.afficherInf();
		System.out.println(this.val);
		d.afficherInf();
	}

	@Override
	Maximier supprimer(int v) {
		Maximier trouve = this.rechercher(v);
		Maximier res = new MaximierVide();
		ArrayList<Integer> valeurs = this.valeursMaximier();
		
		if(!trouve.estVide()) {
			Iterator<Integer> iterator = valeurs.iterator();
			while(iterator.hasNext()) {
				int valeur = iterator.next(); 
				
				if(valeur != v) {
					res = res.inserer(valeur);
				}
			}
		}
		
		return res;
	}
	
	public ArrayList<Integer> valeursMaximier() {
	    ArrayList<Integer> valeurs = new ArrayList<>();
	    valeurs.add(val);
	    
	    if (!g.estVide()) {
	        valeurs.addAll(g.valeursMaximier());
	    }
	    if (!d.estVide()) {
	        valeurs.addAll(d.valeursMaximier());
	    }
	    
	    return valeurs;
	}

	@Override
	Maximier rechercher(int v) {
		Maximier trouve = new MaximierVide();
		
		if(val == v) {
			trouve = this;
		}else {
			trouve = g.rechercher(v);
			if(trouve.estVide()) {
				d = d.rechercher(v);
			}
		}
		
		return trouve;
	}

	@Override
	Integer getVal() {
		return this.val;
	}
	
	@Override
	Integer plusGrandeValeur() {
		Integer res = -1;
		ArrayList<Integer> valeurs = this.valeursMaximier();
		
		Iterator<Integer> iterator = valeurs.iterator();
		while(iterator.hasNext()) {
			Integer current = iterator.next();
			if(res < current) {
				res = current;
			}
		}
		
		return res;
	}

	

	public static void main(String[] args) {
	    Maximier arbre = new Noeud(15, new MaximierVide(), new MaximierVide());
	    arbre = arbre.inserer(10);
	    arbre = arbre.inserer(12);
	    arbre.afficherInf();
	    System.out.println("Plus grande valeur " + arbre.plusGrandeValeur());
	    System.out.println("\n");
	  
	    
	    arbre = arbre.supprimer(15);
	    arbre.afficherInf();
	    System.out.println("Plus grande valeur " + arbre.plusGrandeValeur());
	    System.out.println("\n");
	}

}
