package TP2;

public class FabriquePizzaBretagne implements FabriqueAbstraite {
	Pate pate;
	Garniture gar;
	
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
}
