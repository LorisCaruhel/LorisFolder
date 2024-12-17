package Decorateur;

import java.util.Scanner;

public class Main {

	public Main() {
	}

	public static void main(String[] args) {
		try {
			int choix = -1;
			Composant cafe = null;
			Composant chocolat = null;
			Scanner sc = new Scanner(System.in);
			
			System.out.println("------------ Machine ------------\n");
			System.out.println("Café : 1 (1€)");
			System.out.println("Chocoloat : 2 (1.5€)\n");
			System.out.println("Choississez une boisson : ");
			choix = sc.nextInt();			
			
			switch(choix) {
				case 1 :
					cafe = new BoissonCafe();
					break;
				case 2 :
					chocolat = new BoissonChocolat();
					break;
				default:
					System.out.println("\nPas bien...");
					break;
			}
			
			System.out.println("\nVoulez-vous des suppléments ? (1:oui 0:non)");
			choix = sc.nextInt();
			while(choix != -1) {
				if(choix == 1 || choix == 2) {
					if(choix == 1) {
						System.out.println("\nPepite chocolat : 3 (0.5€)\nPetite Noisette : 4 (1€)\nPlus de lait : 5 (0.20€)");
						choix = sc.nextInt();
					}
					System.out.println("Pas de problème création de la boisson...");
				}
				
				switch(choix) {
					case 3 :
						if(cafe != null) {
							cafe = new PepiteChocolat(cafe);
						} else if(chocolat != null) {
							chocolat = new PepiteChocolat(chocolat);
						}
						break;
					case 4 :
						if(cafe != null) {
							cafe = new PetiteNoisette(cafe);
						} else if(chocolat != null) {
							chocolat = new PetiteNoisette(chocolat);
						}
						break;
					case 5 : 					
						if(cafe != null) {
							cafe = new PlusDeLait(cafe);
						} else if(chocolat != null) {
							chocolat = new PlusDeLait(chocolat);
						}
						break;
					default:
						System.out.println("Quit...\n");
						break;
				}
				
				System.out.println("\nVoulez-vous un autre suppléments ? (1:oui 0:non -1:préparation)");
				choix = sc.nextInt();
			}
			
			if(cafe != null) {
				System.out.println("\n" + cafe.toString() + "\nPrix : " + cafe.getPrix());
			} else if(chocolat != null) {
				System.out.println("\n" + chocolat.toString() + "\nPrix : " + chocolat.getPrix());
			}
			
			sc.close();
		} catch(Exception e) {
			System.out.println("Ce type d'erreur est pris en compte...");
		}
	}

}
