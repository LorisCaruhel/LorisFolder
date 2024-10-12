package TD1.taxeDPStrategie;

public class StrategieTaxeAF extends StrategieTaxeUS {

	public double calcule(int m) {
		return super.calcule(m)*0.8;
	}

}
