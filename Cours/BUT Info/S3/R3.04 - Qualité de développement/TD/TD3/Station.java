package TD3;

public class Station implements Observateur {
	String nom;
	
	Double totalMesure;
	Integer nbMesure = 0;
	Double moyMesure;
	
	public Station(String n) {
		this.nom = n;
	}
	
	@Override
	public void averti(Sujet c) {
		System.out.println("J'ai été averti de la mesure (UK)" + ((Poste)c).getMesure());
		this.totalMesure += ((Poste)c).getMesure();
		this.nbMesure += 1;
		
		this.moyMesure = this.totalMesure / this.nbMesure;
		System.out.println("La moyenne des mesures est de " + this.moyMesure);
	}

}
