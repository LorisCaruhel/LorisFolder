package TD3;

import java.util.ArrayList;
import java.util.Iterator;

public abstract class Sujet {

	ArrayList<Observateur> mesObs;
	
	public Sujet(){
		mesObs = new ArrayList<Observateur>();
	}
	
	public void attache(Observateur o){
		mesObs.add(o);
	}
	
	public void detache(Observateur o){
		mesObs.remove(mesObs.indexOf(o));
	}
	
	public void alerte(){
		Iterator it;
		Observateur o;
		
		it=mesObs.iterator();
		while (it.hasNext()){
			o=(Observateur)(it.next());
			o.averti(this);
		}
	}
	
}
