
public class SmallSmartAR{
	
	private Sequence<Car> carSequence;
	
	public SmallSmartAR()
	{
//		System.out.println("USING SMALL SMART AR");
		carSequence=new Sequence<Car>();
	}
	
	public Sequence<Car> getSequence()
	{
		return carSequence;
	}
	

	public void generate(int n) {
		for(int i=0;i<n;i++)
		{
			String s=SmartAR.randomGenerateString();
			while(this.find(s)!=null)
			{
				s=SmartAR.randomGenerateString();
			}
			this.add(s, 0);
		}	
	}

	public void add(String key, int value) {
		//assume we only have one value, which is the register year
		Car newCar=new Car(key,value);
		carSequence.sortedAdd(newCar);
	}

	public void remove(String key) {
		if(this.find(key)==null)
		{
			System.out.println("Unable to remove this key.");
		}
		else
		{
			System.out.println("Plate "+key+" has been removed.");
			this.carSequence.remove(find(key));
		}
	}

	public Car[] getValues(String key) {
		if(this.find(key)==null)
		{
			System.out.println("No such item in the data base.");
			return null;
		}
		else
		{
			System.out.println(find(key));
			return find(key).getElements();
		}
	}

	public String nextKey(String key) {
		Position<Car> place=this.find(key);
		if(place==null||carSequence.next(place)==null)
		{
			return null;
		}
		else
		{
			return carSequence.next(place).getElements()[0].getLicensePlate();
		}
	}

	public String prevKey(String key) {
		Position<Car> place=this.find(key);
		if(place==null||carSequence.prev(place)==null)
		{
			System.out.println("Can't find this key in data base");
			return null;
		}
		else
		{
			return carSequence.prev(place).getElements()[0].getLicensePlate();
		}
	}

	public String[] allKey() {
		String[] plateArray=new String[carSequence.size()];
		if(!carSequence.isEmpty())
		{
			Position<Car> first=carSequence.first();
			int i=0;
			while(first!=null)
			{
				plateArray[i]=(first.getElements()[0].getLicensePlate());
				first=carSequence.next(first);
				i++;
			}
		}
		for(int i=0;i<plateArray.length;i++)
		{
			System.out.println(plateArray[i]);		
		}
		return plateArray;
	}

	public Car[] previousCars(String key) {
		if(this.find(key)==null)
		{
			System.out.println("No such item in the data base.");
			return null;
		}
		else
		{
			Position<Car> place=find(key);
			carSequence.sortPlate(place);
			Car[] previousCars=place.getElements();
			System.out.println("Here are the cars that registered under the plate "+key+" displayed in reverse chronological order:");
			for(int i=0;i<previousCars.length;i++)
			{
				if(previousCars[i]!=null)
				{
					System.out.println(previousCars[i]);
				}
			}
			return previousCars;		
		}
	}

	public BigSmartAR move() {
		System.out.println("Move data from smallSmartAR to bigSmartAR");
		BigSmartAR target=new BigSmartAR();
		if(!carSequence.isEmpty())
		{
			Position<Car> first=carSequence.first();
			while(first!=null)
			{
				Car[] cararray=first.getElements();
				for(int i=0;i<cararray.length;i++)
				{
					if(cararray[i]!=null)
					{
						target.add(cararray[i].getLicensePlate(), cararray[i].getRegisterYear());
					}
				}
				first=carSequence.next(first);
			}
		}
		return target;
	}
	
	public int size() {
		return carSequence.size(); 
	}
	
	private Position<Car> find(String key)
	{
		if(this.carSequence.isEmpty())
		{
			return null;
		}
		else if(carSequence.last().getElements()[0].getLicensePlate()==key)
		{
			return carSequence.last();
		}
		else
		{
			Position<Car> temp=carSequence.first();
			while(carSequence.next(temp)!=null)
			{
				if(temp.getElements()[0].getLicensePlate()==key)
				{
					return temp;
				}
				else
				{
					temp=carSequence.next(temp);
				}
			}
			return null;
		}
	}
	
	public String toString()
	{
		return this.carSequence.toString();
		
	}
}
