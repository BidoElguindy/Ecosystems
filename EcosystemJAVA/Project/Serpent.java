public class Serpent extends Animal{

	public Serpent(String nom){
		super(nom)
	}
	public String toString(){
		return "Serpent qui s'applle " + super.toString();
	}
	public void mange(){
		this.boost(5);
		System.out.println(nom + " gagne 5 energie");
	}

	public void boie(){
		this.boost(3);
		System.out.println(nom + " gagne 3 energie");
	}

}