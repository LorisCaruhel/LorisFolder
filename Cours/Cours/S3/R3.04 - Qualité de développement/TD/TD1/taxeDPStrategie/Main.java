package TD1.taxeDPStrategie;

public class Main {
	public static void main(String[] args) {	
		 CommandeEU c1 = new CommandeEU("Caruhel", 100);
		 CommandeUS c2 = new CommandeUS("Test", 100);
		 CommandeAF c3 = new CommandeAF("Test", 100);
		 
		 System.out.println(c1.toString());
		 System.out.println(c2.toString());
		 System.out.println(c3.toString());
	}

}
