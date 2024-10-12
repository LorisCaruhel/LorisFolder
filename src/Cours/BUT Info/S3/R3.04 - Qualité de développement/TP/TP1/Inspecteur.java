package Qualite_dev;

public class Inspecteur extends Personne {
	private volatile static Inspecteur ins = null;
	
	private Inspecteur(String nom) {
		super(nom);
	}
	
	public static Inspecteur getInstance() {
		if(ins == null) {
			synchronized (Inspecteur.class) {
				ins = new Inspecteur(null);
			}
		}
		return ins;
	}
	
	public static void setNomIns(String nom) {
		ins.setNom(nom);
	}
	
	public void afficherEnseignant() {
		System.out.println(this.toString());
	}

	@Override
	public String toString() {
		return "C'est un inspecteur qui s'appelle : " + this.getNom();
	}
	
	public static void main(String[] args) {
		Inspecteur ins1 = Inspecteur.getInstance();
		Inspecteur ins2 = Inspecteur.getInstance();
		
		Inspecteur.setNomIns("Moi");
		
		System.out.println(ins1);
		System.out.println(ins2);
		System.out.println(ins1 == ins2);
	}
}
