public abstract class Singe extends Animal{
	//Le singe a 4 evolution qui depend de son energie si il atteint la 4e evolution il ne peut plus mourir.
	private int evolution;
	public static final int MAX_EVOLUTION=4;

	//Constructeurs
	public Singe(String nom){
		super(nom);
		evolution=1;
	}

	public String toString(){
		return "Singe qui s'applle " + super.toString();
	}

	//Les getters
	public String getNom(){
		return super.nom;
	}

	public int getEnergie(){
		return super.energie;
	}

	public int getEvolution(){
		return evolution;
	}

	public void boost(int e){
		super.energie=super.energie + e;
	}
	public void mange(){
		this.boost(5);
		System.out.println(nom + " gagne 5 energie");
	}

	public void boie(){
		this.boost(3);
		System.out.println(nom + " gagne 3 energie");
	}

	public void evoltionDuSinge(){
		if (super.energie>=50){
			energie=4;
			System.out.println("Le singe est Imortelle, " + nom +" gagne");
		}
		else if (super.energie>=25){
			energie=3;
			System.out.println(nom + " evolue a sa troisième évolution");
		}
		else if (super.energie>=15){
			energie=2;
			System.out.println(nom + "  evolue a sa deuxieme évolution");

		}
	}

		


}