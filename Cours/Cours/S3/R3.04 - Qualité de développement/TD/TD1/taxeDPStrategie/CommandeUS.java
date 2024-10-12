package TD1.taxeDPStrategie;

public class CommandeUS extends Commande {
	
	public CommandeUS(String c, int mHT) {
		super(c, mHT, new StrategieTaxeUS());
	}

}
