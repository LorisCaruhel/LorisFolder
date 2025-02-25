package PizzaDecorateur;

public class FabriquePizzaAlsace implements FabriqueAbstraite, Composant {
	Pate pate;
	Garniture gar;
	Composant item;
	
	public FabriquePizzaAlsace(Composant item) {
		this.item = item;
	}
	
	public FabriquePizzaAlsace() {
		
	}

	@Override
	public void creePate() {
		this.pate = new PateEpaisse();
		System.out.println("Pâte faite !");
	}

	@Override
	public void creeGarniture() {
		this.gar = new GarnitureAlsacienne();
		System.out.println("Garniture faite !");
	}

	public void afficherPizza() {
		System.out.println("\nPizza alsacienne : ");
		this.pate.affiche();
		this.gar.affiche();
	}

	@Override
	public double getPrix() {
		return 0;
	}
}
