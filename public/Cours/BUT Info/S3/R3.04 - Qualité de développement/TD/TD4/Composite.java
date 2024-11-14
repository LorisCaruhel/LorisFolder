package TD4;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

import TD3.Observateur;

public class Composite extends Composant{
	public Collection<Composant> mesFils;
	
	public Composite() {
		this.mesFils = new ArrayList<Composant>(20);
	}
	
	public void mesComposant() {
		Iterator<Composant> it;
		Observateur o;
		
		it=mesFils.iterator();
		while (it.hasNext()){
			o=(Observateur)(it.next());
			// Afficher tous les fils.
			System.out.println(o.toString());
		}
	}
}
