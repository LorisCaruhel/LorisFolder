package TP3;

public class Processus {
	int id;
	int prio;
	
	public Processus(int i, int p) {
		id=i;
		prio=p;
	}
	
	public Integer getPrio() {
		return this.prio;
	}
	
	public String toString() {
		return "\nProcessus numero : " + id + " et de priorite " + prio + "\n";
	}
	
	public boolean plusPrioritaire(Processus p) {
		 return this.prio>p.prio;
	}

	public void setPrio(Integer valeur) {
		this.prio = valeur;
	}
}
