package TD2;

public class EtatFermer implements Etat {
	Porte porte;
	
	public EtatFermer(Porte p) {
		this.porte = p;
	}

	@Override
	public void appuyer() {
		System.out.println("Ouverture...");
		this.porte.modifierEtat(porte.getOuvert());
	}

	@Override
	public void terminer() {
		System.out.println("Déjà fermer...");
	}

}
