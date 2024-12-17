package PizzaDecorateur;

public class Anchois extends Decorateur {

	public Anchois(Composant item) {
		super(item);
	}

	@Override
	public double getPrix() {
		return 2 + this.item.getPrix();
	}

}
