package PizzaDecorateur;

public abstract class Decorateur implements Composant {
	Composant item;
	
	public Decorateur(Composant item) {
		this.item = item;
	}

}
