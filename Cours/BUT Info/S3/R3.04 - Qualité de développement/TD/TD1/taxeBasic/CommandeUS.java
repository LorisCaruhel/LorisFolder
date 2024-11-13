package TD1.taxeBasic;

public class CommandeUS extends Commande {
	private static int TAXE_US = 8;
	
	public CommandeUS(String n, double d) {
		super(n, d);
	}

	@Override
	public double calculTaxe() {
		return 10+((TAXE_US*this.getHT())/100);
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
