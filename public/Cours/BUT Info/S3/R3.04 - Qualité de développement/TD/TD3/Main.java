package TD3;

public class Main {

	public Main() {
		
	}

	public static void main(String[] args) {
		// Les postes
		Poste brest = new Poste("Brest");
		Poste paris = new Poste("Paris");
		Poste lyon = new Poste("Lyon");
		Poste londres = new Poste("Londres");
		Poste southampton = new Poste("Southampton");
		
		// Les stations
		Station eu = new Station("Europe");
		Station uk = new Station("UK");
		Station fr = new Station("France");
		
		// Attacher ses observateurs
		brest.attache(eu);
		brest.attache(uk);
		brest.attache(fr);
		
		paris.attache(fr);
		paris.attache(eu);
		
		lyon.attache(fr);
		lyon.attache(eu);
		
		londres.attache(eu);
		londres.attache(uk);
		
		southampton.attache(eu);
		southampton.attache(uk);
		southampton.attache(fr);
		
		// Les tests
		
	}

}
