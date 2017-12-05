
public class Car implements Comparable<Car>{
	
	private String licensePlate;
	private int registerYear;
	private String owner;
	
	public Car()
	{
		licensePlate=null;
		registerYear=0;
		owner=null;
	}
	
	public Car(String licensePlate)
	{
		this.licensePlate=licensePlate;
	}
	
	public Car(String licensePlate, int year)
	{
		this.licensePlate=licensePlate;
		this.registerYear=year;
	}
	
	public Car(String licensePlate, int year, String name)
	{
		this.licensePlate=licensePlate;
		this.registerYear=year;
		this.owner=name;
	}

	public String getLicensePlate() {
		return licensePlate;
	}

	public void setLicensePlate(String licensePlate) {
		this.licensePlate = licensePlate;
	}

	public int getRegisterYear() {
		return registerYear;
	}

	public void setRegisterYear(int registerYear) {
		this.registerYear = registerYear;
	}

	public String getOwner() {
		return owner;
	}

	public void setOwner(String owner) {
		this.owner = owner;
	}

	@Override
	public String toString() {
		return "Car [licensePlate=" + licensePlate + ", registerYear=" + registerYear + ", owner=" + owner + "]";
	}


	@Override
	public int compareTo(Car o) {
//		if(this.getLicensePlate()==o.getLicensePlate())
//		{
//		   return 0; 
//		} 
		if(this.getRegisterYear() < o.getRegisterYear())
		{
		     return -1;
		}
		else
		{
			return 1;
		}
	}

	
	
}
