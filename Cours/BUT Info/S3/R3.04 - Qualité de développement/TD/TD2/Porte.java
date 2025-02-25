package TD2;

public class Porte {
	EtatFermer fermer;
	EtatOuvert ouvert;
	EtatEnCoursFermeture enCoursF;
	EtatEnCoursOuverture enCoursO;
	
	Etat etatCourant;
	
	public Porte() {
		this.fermer = new EtatFermer(this);
		this.ouvert = new EtatOuvert(this);
		this.enCoursF = new EtatEnCoursFermeture(this);
		this.enCoursO = new EtatEnCoursOuverture(this);
		etatCourant = this.fermer;
	}

	public EtatEnCoursFermeture getEnCoursF() {
		return this.enCoursF;
	}

	public EtatEnCoursOuverture getEnCoursO() {
		return this.enCoursO;
	}

	public Etat getEtatCourant() {
		return this.etatCourant;
	}
	
	public Etat getFermer() {
		return this.fermer;
	}
	
	public Etat getOuvert() {
		return this.ouvert;
	}
	
	public void modifierEtat(Etat e) {
		this.etatCourant = e;
	}
	
	public void appuyer() {
		this.etatCourant.appuyer();
	}
	
	public void terminer() {
		this.etatCourant.terminer();
	}
	
	public static void main(String[] args) {
		Porte p = new Porte();
		p.terminer();
		p.appuyer();
		p.appuyer();
		p.terminer();	
		p.terminer();
	}
	
}

