package TD1.taxeDPStrategie;

public class CommandeAF extends Commande {

	public CommandeAF(String c, int mHT) {
		super(c, mHT, new StrategieTaxeAF());
	}

}
