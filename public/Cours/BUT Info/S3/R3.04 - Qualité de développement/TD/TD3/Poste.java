package TD3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Poste extends Sujet {
	String nom;
	Double mesure;
	
	public Poste(String n) {
		super();
		this.nom = n;
	}
		
	public void faireMesure() {
		try {
			Scanner sc = new Scanner(System.in);
			Double mesure = sc.nextDouble();
			
			this.alerte();
		} catch(InputMismatchException e) {
			System.out.println("Erreur de saisie");
		}
	}
	
	public Double getMesure() {
		return this.mesure;
	}
}
