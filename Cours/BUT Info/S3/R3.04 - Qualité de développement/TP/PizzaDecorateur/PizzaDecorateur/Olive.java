package PizzaDecorateur;

public class Olive extends Decorateur {

	public Olive(Composant item) {
		super(item);
	}

	@Override
	public double getPrix() {
		return 2 + this.item.getPrix();
	}

}
