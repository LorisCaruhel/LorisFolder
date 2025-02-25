package Decorateur;

public class PepiteChocolat extends Decorateur {
	
	public PepiteChocolat(Composant item) {
		super(item);
	}

	@Override
	public double getPrix() {
		return 0.5 + this.item.getPrix();
	}
	
	public String toString() {
		return this.item.toString() + " + Pépite chocolat";
	}

}
