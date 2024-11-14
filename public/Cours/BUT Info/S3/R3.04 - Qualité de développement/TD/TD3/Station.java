package TD3;

public class Station implements Observateur {
	String nom;
	
	double totalMesure;
	int nbMesure;
	double moyMesure;
	
	public Station(String n) {
		this.nom = n;
		this.totalMesure = 0.0;
		
	}
	
	@Override
	public void averti(Sujet c) {
		System.out.println("J'ai été averti de la mesure " + this.nom + " " + ((Poste)c).getMesure());
		this.totalMesure = this.totalMesure + ((Poste)c).getMesure();
		this.nbMesure = this.nbMesure + 1;
		
		this.moyMesure = this.totalMesure / this.nbMesure;
		System.out.println("La moyenne des mesures est de " + this.moyMesure);
	}

}
