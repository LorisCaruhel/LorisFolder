package PizzaDecorateur;

public class Client {
	String nom;
	Composant pizzaB;
	Composant pizzaA;
	
	public Client(String n) {
		this.nom = n;
	}

	public void creePizzaBretonne() {
		this.pizzaB = new FabriquePizzaBretagne();
		this.pizzaB.creePate();
		this.pizzaB.creeGarniture();
	}
	
	public void creePizzaAlsacienne() {
		this.pizzaA = new FabriquePizzaAlsace();
		this.pizzaA.creePate();
		this.pizzaA.creeGarniture();
	}
	
	public static void main(String[] args) {
		Client c1 = new Client("PizzaDeLaMama");
		
		c1.creePizzaBretonne();
		System.out.println("\n");
		c1.creePizzaAlsacienne();
		
		c1.pizzaA.afficherPizza();
		c1.pizzaB.afficherPizza();
		
		c1.pizzaA = new Olive(c1.pizzaA);
	}

}
