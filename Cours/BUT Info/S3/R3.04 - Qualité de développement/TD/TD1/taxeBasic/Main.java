package TD1.taxeBasic;

public class Main {

	public Main() {
		
	}

	public static void main(String[] args) {
		CommandeEU c1 = new CommandeEU("Caruhel", 152.36);
		CommandeUS c2 = new CommandeUS("Test", 205.46);
		
		System.out.println(c1.toString());
		System.out.println(c2.toString());
	}

}
