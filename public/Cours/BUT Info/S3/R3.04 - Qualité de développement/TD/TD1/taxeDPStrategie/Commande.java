package TD1.taxeDPStrategie;

public abstract class Commande {
	String cli;
	int montantHT;

	StrategieTaxe strategie;
	
	public Commande(String c, int mHT, StrategieTaxe s) {
		this.cli = c;
		this.montantHT = mHT;
		this.strategie = s;
	}
	
	double calculerTaxe() {
		return strategie.calcule(montantHT);
	}
	
	public String toString() {
		return "Nom du client de la commande : " + this.getNomCli() + "\n" +
				"Montant de la commande HT : " + this.calculerTaxe() + "\n" + 
				"Montant de la commande TTC : " + (this.montantHT + this.calculerTaxe()) + "\n";
	}

	public String getNomCli() {
		return this.cli;
	}

	public void setNomCli(String nomCli) {
		this.cli = nomCli;
	}
	
	public double getHT() {
		return montantHT;
	}

	public void setHT(int hT) {
		this.montantHT = hT;
	}
}
