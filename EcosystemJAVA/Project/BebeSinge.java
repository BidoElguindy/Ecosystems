public class BebeSinge extends Singe{
	public BebeSinge(String nom){
		super(nom);
	}
	public String toString(){
		return "Un bébé " + super.toString();
	}

	public void mange(){
		this.boost(5);
	}
	public void boie(){
		this.boost(3);
	}

}