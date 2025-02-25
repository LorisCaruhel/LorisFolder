package Decorateur;

public class BoissonCafe implements Composant {

	public BoissonCafe() {
		
	}

	@Override
	public double getPrix() {
		return 1;
	}
	
	public String toString() {
		return "Boisson café";
	}

}
