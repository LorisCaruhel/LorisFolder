package TD4;

public class Veau extends Met{

	public Veau(String _nom, boolean _sucre, boolean _sale, int _calories) {
		super(_nom, _sucre, _sale, _calories);
	}

	public String toString() {
		String s = super.toString();
		return s;
	}
	
	public void affiche() {
		System.out.println(this.toString());
	}
}
