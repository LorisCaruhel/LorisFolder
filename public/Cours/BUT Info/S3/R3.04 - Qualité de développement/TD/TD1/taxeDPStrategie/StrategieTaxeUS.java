package TD1.taxeDPStrategie;

public class StrategieTaxeUS implements StrategieTaxe {
	
	public double calcule(int m) {
		return (10+0.08*m);
	}
}

