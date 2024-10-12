package TP2;

public class FabriquePizzaAlsace implements FabriqueAbstraite {
	Pate pate;
	Garniture gar;
	
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
}
