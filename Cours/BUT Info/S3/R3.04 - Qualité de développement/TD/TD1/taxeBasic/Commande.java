package TD1.taxeBasic;

public abstract class Commande {
	private String nomCli;
	private double HT;
	

	public Commande(String n, double HorsTaxe) {
		this.nomCli = n;
		this.HT = HorsTaxe;
	}

	public abstract double calculTaxe();
	public abstract double calculTTC();
	
	public String getNomCli() {
		return nomCli;
	}

	public void setNomCli(String nomCli) {
		this.nomCli = nomCli;
	}
	
	public double getHT() {
		return HT;
	}

	public void setHT(Float hT) {
		HT = hT;
	}
}
