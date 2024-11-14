package TP3;

public class Main {

	public Main() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Composite maximier = Maximier.createVide();
		maximier = maximier.inserer(new Processus(1, 1));
		maximier = maximier.inserer(new Processus(2, 2));
		maximier = maximier.inserer(new Processus(3, 3));
		maximier = maximier.inserer(new Processus(4, 4));
		maximier = maximier.inserer(new Processus(5, 5));
		maximier = maximier.inserer(new Processus(6, 6));
		maximier = maximier.inserer(new Processus(7, 7));
		
		System.out.println("\n\n-------- Le plus prioritaire avant suppression --------");
		System.out.println(maximier.suivant().toString());
		
		System.out.println("\n\n-------- Affichage avant suppression --------");
		maximier.afficherInfixe();
		System.out.println("\n\n-------- Suppression --------");
		System.out.println("Poids avant suppression : " + maximier.getPoids() + "\n");
		maximier.supprimer();
		System.out.println("Poids après suppression : " + maximier.getPoids());
		
		System.out.println("\n\n-------- Le plus prioritaire après suppression --------");
		System.out.println(maximier.suivant().toString());
		
		System.out.println("\n\n-------- Affichage après suppression --------");
		maximier.afficherInfixe();
	}

}
