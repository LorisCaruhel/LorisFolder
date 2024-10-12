package TD2;

public class EtatEnCoursOuverture implements Etat {
	Porte porte;
	
	public EtatEnCoursOuverture(Porte p) {
		this.porte = p;
	}

	@Override
	public void appuyer() {
		System.out.println("Déjà en cours d'ouverture...");
	}

	@Override
	public void terminer() {
		System.out.println("Fermeture...");
		this.porte.modifierEtat(porte.getEnCoursF());
	}
}
