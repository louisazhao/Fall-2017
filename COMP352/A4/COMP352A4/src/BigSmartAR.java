
public class BigSmartAR{
	
	private AVLTree<Car> carTree;
	
	public BigSmartAR()
	{
//		System.out.println("USING BIG SMART AR");
		carTree=new AVLTree<Car>();
	}
	

	public void generate(int n) 
	{
		for(int i=0;i<n;i++)
		{
			String s=SmartAR.randomGenerateString();
			while(this.carTree.contains(carTree.getRoot(),s))
			{
				s=SmartAR.randomGenerateString();
			}
			this.add(s, 0);
		}	
	}

	
	public void add(String key, int value) {
		Car newCar=new Car(key,value);
		carTree.add(newCar);	
	}

	
	public void remove(String key) {
		if(!this.carTree.contains(carTree.getRoot(),key))
		{
			System.out.println("Unable to remove this key.");
		}
		else
		{
			this.carTree.remove(key);
		}
		
	}

	
	public Car[] getValues(String key) {
		if(!this.carTree.contains(carTree.getRoot(), key))
		{
			System.out.println("No such item in the data base.");
			return null;
		}
		else
		{
			System.out.println(this.carTree.find(this.carTree.getRoot(), key));
			return this.carTree.find(this.carTree.getRoot(), key).getElements();
		}
	}

	
	public String nextKey(String key) {
		TreeNode<Car> node=this.carTree.find(this.carTree.getRoot(), key);
		if(node==null)
		{
			System.out.println("Unable to find next key.");
			return null;
		}
		else
		{
			return this.carTree.nextNode(node).getElements()[0].getLicensePlate();
		}
	}

	
	public String prevKey(String key) {
		TreeNode<Car> node=this.carTree.find(this.carTree.getRoot(), key);
		if(node==null)
		{
			System.out.println("Unable to find next key.");
			return null;
		}
		else
		{
			return this.carTree.prevNode(node).getElements()[0].getLicensePlate();
		}
	}

	
	public String[] allKey() {
		String[] keys=new String[this.carTree.size()];
		int i=0;
		while(this.carTree.iterator().hasNext())
		{
			Car[] s=this.carTree.iterator().next();
			System.out.println(s[0].getLicensePlate());
			keys[i]=s[0].getLicensePlate();	
			i++;
		}
		this.carTree.resetIterator();
		return keys;
	}

	
	public Car[] previousCars(String key) {
		TreeNode<Car> node=this.carTree.find(this.carTree.getRoot(), key);	
		if(node==null)
		{
			System.out.println("Unable to find the key.");
			return null;
		}
		else
		{
			Car[] cars=new Car[node.elementCounter()];
			for(int i=0;i<node.elementCounter();i++)
			{
				cars[i]=node.getElements()[i];
			}
			//bubble sort
			for(int i=0;i<cars.length;i++)
			{
				for(int j=1;j<cars.length-i;j++)
					{
						if(cars[j-1].compareTo(cars[j])<0)//reverse order
						{
							Car temp=cars[j-1];
							cars[j-1]=cars[j];
							cars[j]=temp;
						}
					}
			}
			System.out.println("Here are the cars that registered under the plate "+key+" displayed in reverse chronological order:");
			for(int i=0;i<cars.length;i++)
			{
				System.out.println(cars[i]);
			}
			return cars;
		}	
	}

	public SmallSmartAR move() {
		System.out.println("Move data from bigSmartAR to smallSmartAR");
		SmallSmartAR target=new SmallSmartAR();
		if(carTree.getRoot()!=null)
		{
			while(this.carTree.iterator().hasNext())
			{
				Car[] s=this.carTree.iterator().next();
				for(int i=0;i<s.length;i++)
				{
					if(s[i]!=null)
					target.add(s[i].getLicensePlate(), s[i].getRegisterYear());
				}		
			}
		}
		return target;
	}
		

	
	public int size() {
		return this.carTree.size();
	}
	
	public String toString()
	{
		return this.carTree.toSting();
	}

}
