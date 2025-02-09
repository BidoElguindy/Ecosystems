public class AdulteSinge extends Singe implements Win{
	public AdulteSinge(String nom){
		super(nom);
	}
	public String toString(){
		return "Un adulte " + super.toString();
	}
	public void gagne(){
		if(super.getEnergie()>=50){
			System.out.println(super.getNom() + " gagne");
		}
	}
	public void mange(){
		this.boost(5);
	}
	public void boie(){
		this.boost(3);
	}
}