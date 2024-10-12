package TD1.garage;

import java.util.ArrayList;
import java.util.Collection;

public class Garage {
	private String nom;
	private int capital;
	private Collection<Voiture> voitures; 
	private StrategieValeur s;
	
	public Garage(String n, int c) {
		this.nom = n;
		this.capital = c;
		voitures = new ArrayList<Voiture>();
	}

	
}
