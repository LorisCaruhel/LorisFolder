package Decorateur;

public class PlusDeLait extends Decorateur {

	public PlusDeLait(Composant item) {
		super(item);
	}

	@Override
	public double getPrix() {
		return 0.2 + this.item.getPrix();
	}
	
	public String toString() {
		return this.item.toString() + " + Plus de lait";
	}

}
