package Decorateur;

public class PetiteNoisette extends Decorateur {

	public PetiteNoisette(Composant item) {
		super(item);
	}

	@Override
	public double getPrix() {
		return 1 + this.item.getPrix();
	}
	
	public String toString() {
		return this.item.toString() + " + Petite noisette";
	}

}
