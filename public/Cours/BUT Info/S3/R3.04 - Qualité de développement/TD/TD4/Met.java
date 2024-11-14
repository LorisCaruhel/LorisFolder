package TD4;

public class Met {
	public String nom;
	public boolean sucre;
	public boolean sale;
	public int calories;
	
	public Met(String _nom, boolean _sucre, boolean _sale, int _calories) {
		this.nom = _nom;
		this.sucre = _sucre;
		this.sale = _sale;
		this.calories = _calories;
	}

	public Boolean estSucre() {
		return this.sucre;
	}
	
	public Boolean estSale() {
		return this.sale;
	}
	
	public Boolean estSucreSale() {
		return (this.sucre && this.sale);
	}
	
	public int nombreDeCalories() {
		return this.calories;
	}
	
	public Boolean estDiatetique() {
		return (this.calories < 200);
	}
	
	public String toString() {
		return "Met : " + this.nom;
	}
	
	public void affiche() {
		System.out.println(this.toString());
	}
}
