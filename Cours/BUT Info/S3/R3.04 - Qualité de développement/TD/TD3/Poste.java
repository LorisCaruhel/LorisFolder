package TD3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Poste extends Sujet {
	public String nom;
	public double mesure;
	
	public Poste(String n) {
		super();
		this.nom = n;
	}
		
	public void faireMesure() {
		Scanner sc = new Scanner(System.in);
		try {
			String x;
			System.out.println("\nEntrez une mesure : ");
			x = sc.nextLine();
			double y = Double.parseDouble(x);
			this.setMesure(y);
			
			this.alerte();
		} catch(InputMismatchException e) {
			System.out.println("Erreur de saisie");
		}
	}
	
	public void setMesure(Double m) {
		this.mesure = m;
	}
	
	public Double getMesure() {
		return this.mesure;
	}
}
