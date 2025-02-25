package TD1.taxeBasic;

public class CommandeEU extends Commande {
	private final int TAXE_EU = 15;
	
	public CommandeEU(String n, double d) {
		super(n, d);
	}

	@Override
	public double calculTaxe() {
		return (TAXE_EU*this.getHT())/100.0;
	}

	@Override
	public double calculTTC() {
		return this.getHT()+this.calculTaxe();
	}
	
	public String toString() {
		return "Nom du client de la commande : " + this.getNomCli() + "\n" +
				"Montant de la commande HT : " + this.calculTaxe() + "\n" +
				"Montant de la commande TTC : " + this.calculTTC() + "\n";
	}
}
