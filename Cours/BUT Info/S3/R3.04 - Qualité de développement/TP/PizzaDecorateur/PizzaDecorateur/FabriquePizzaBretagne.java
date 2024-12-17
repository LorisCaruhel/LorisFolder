package PizzaDecorateur;

public class FabriquePizzaBretagne implements FabriqueAbstraite, Composant {
	Pate pate;
	Garniture gar;
	Composant item;
	
	public FabriquePizzaBretagne(Composant item) {
		this.item = item;
	}
	
	public FabriquePizzaBretagne() {

	}

	@Override
	public void creePate() {
		this.pate = new PateFine();
		System.out.println("Pâte faite !");
	}

	@Override
	public void creeGarniture() {
		this.gar = new GarnitureBretagne();
		System.out.println("Garniture faite !");
	}

	public void afficherPizza() {
		System.out.println("\nPizza Bretonne : ");
		this.pate.affiche();
		this.gar.affiche();
	}

	@Override
	public double getPrix() {
		return 20 + this.item.getPrix();
	}
}
