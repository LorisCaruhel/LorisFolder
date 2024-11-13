package TD2;

public class EtatEnCoursFermeture implements Etat {
	Porte porte;
	
	public EtatEnCoursFermeture(Porte p) {
		this.porte = p;
	}

	@Override
	public void appuyer() {
		System.out.println("Ouverture...");
		this.porte.modifierEtat(porte.getEnCoursO());
	}

	@Override
	public void terminer() {
		System.out.println("Déjà en fermeture...");
	}

}
