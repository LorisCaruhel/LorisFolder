package TD2;

public class EtatOuvert implements Etat {
	Porte porte;
	
	public EtatOuvert(Porte p) {
		this.porte = p;
	}

	@Override
	public void appuyer() {
		System.out.println("Fermeture...");
		this.porte.modifierEtat(porte.getFermer());
	}

	@Override
	public void terminer() {
		System.out.println("Déjà fermer...");
	}

}
