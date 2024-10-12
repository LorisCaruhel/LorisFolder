package TD1.taxeDPStrategie;

public class CommandeEU extends Commande{
	
	public CommandeEU(String c, int mHT) {
		super(c, mHT, new StrategieTaxeEU());
	}
}
