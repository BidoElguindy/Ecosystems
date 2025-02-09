public class AdoSinge extends Singe{
	public AdoSinge(String nom){
		super(nom);
	}
	public String toString(){
		return "Un adolescent " + super.toString();
	}
	public void mange(){
		this.boost(5);
	}
	public void boie(){
		this.boost(3);
	}
}