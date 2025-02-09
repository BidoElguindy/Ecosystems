public abstract class Animal{
	protected String nom;
	protected int energie;
	public Animal(int energie,String nom){
		this.nom=nom;
		this.energie=energie;
	}
	public Animal(String nom){
		this(5,nom);
	}
	public String toString(){
		return nom + " a energie " + energie;
	}
	public String getNom(){
		return nom;
	}
	public int getEnergie(){
		return energie;
	}
	public abstract void mange();

	public abstract void boie();


}