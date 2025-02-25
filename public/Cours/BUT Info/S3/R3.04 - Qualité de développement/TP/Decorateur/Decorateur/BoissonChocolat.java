package Decorateur;

public class BoissonChocolat implements Composant {
	
	public BoissonChocolat() {

	}

	@Override
	public double getPrix() {
		return 1.5;
	}
	
	public String toString() {
		return "Boisson chocolat";
	}

}
