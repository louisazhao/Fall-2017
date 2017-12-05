public class SmartAR {
	public static int threshold=7;
	public static int keyLength=6;
	public static final String ALPHA_NUMERIC_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	protected SmallSmartAR smallList;
	protected BigSmartAR bigList;
//	private SmartAR list;
	
	public SmartAR()
	{
		smallList=new SmallSmartAR();
		bigList=new BigSmartAR();
	}

	
	public int getThreshold()
	{
		return threshold;
	}
	
	public void setThreshold(int value)
	{
		if(value>=100&&value<=500000)
			{threshold=value;}
		else
		{
			System.out.println("Threshold must be between 100 and 500000");
		}
		
	}
	
	public int getKeyLength()
	{
		return keyLength;
	}
	
	public void setKeyLength(int value)
	{
		if(value>=6&&value<=12){
			keyLength=value;
		}
		else
			System.out.println("Key length must be between 6 and 12");
	}
	
	public static String randomGenerateString()
	{
		String s="";
		int count=keyLength;
		while(count!=0)
		{
			int position=(int)(Math.random()*ALPHA_NUMERIC_STRING.length());
			s+=(ALPHA_NUMERIC_STRING.charAt(position));
			count--;
		}
		return s;
	}
	
	private boolean smallIsFull()
	{
		return (smallList.size()>=threshold);
	}
	
//	private boolean bigIsWaste()
//	{
//		return (bigList.size()<threshold);
//	}
	public void generate(int n)
	{
		if(smallList!=null&&!this.smallIsFull())
		{
			smallList.generate(n);
			if(this.smallIsFull())
			{
				System.out.println("---------------------------");
				System.out.println("Moving to big data type");
				System.out.println("---------------------------");
				moveToBig();
			}
		}
		else
		{
			bigList.generate(n);
		}
	}
	public String[] allKey()
	{
		if(smallList==null)
		{
			return bigList.allKey();
		}
		else if(bigList==null)
		{
			return smallList.allKey();
		}
		else
		{
			System.out.println("Error");
			return null;
		}
	}
	public int size()
	{
		int size=0;
		if(smallList==null)
		{
			size=bigList.size();
		}
		else if(bigList==null)
		{
			size=smallList.size();
		}
		return size;
	}
	public void add(String key, int value)
	{
		if(smallList!=null&&!this.smallIsFull())
		{
			smallList.add(key, value);
//			System.out.println("1");
			if(this.smallIsFull())
			{
				System.out.println("---------------------------");
				System.out.println("Moving to big data type");
				System.out.println("---------------------------");
				moveToBig();
			}
		}
		else
		{
			bigList.add(key, value);
//			System.out.println("2");
		}
		
	}
	public void remove(String key)
	{
		if(this.size()==0)
		{
			System.out.println("Empty database, unable to remove");
		}
		if(smallList!=null)
		{
			smallList.remove(key);
		}
		else
		{
			bigList.remove(key);
			if(bigList.size()<threshold)
			{
				System.out.println("---------------------------");
				System.out.println("Moving to small data type");
				System.out.println("---------------------------");
				moveToSmall();
			}
		}
	}
	public Car[] getValues(String key)
	{
		if(smallList==null)
		{
			return bigList.getValues(key);
		}
		else if(bigList==null)
		{
			return smallList.getValues(key);
		}
		else
		{
			System.out.println("ERROR");
			return null;
		}		
	}
	public String nextKey(String key)
	{
		if(smallList==null)
		{
			return bigList.nextKey(key);
		}
		else if(bigList==null)
		{
			return smallList.nextKey(key);
		}
		else
		{
			System.out.println("ERROR");
			return null;
		}
	}
	public String prevKey(String key)
	{
		if(smallList==null)
		{
			return bigList.prevKey(key);
		}
		else if(bigList==null)
		{
			return smallList.prevKey(key);
		}
		else
		{
			System.out.println("ERROR");
			return null;
		}
	}
	public Car[] previousCars(String key)
	{
		if(smallList==null)
		{
			return bigList.previousCars(key);
		}
		else if(bigList==null)
		{
			return smallList.previousCars(key);
		}
		else
		{
			System.out.println("ERROR");
			return null;
		}
	}
	
	private void moveToBig()
	{
		bigList=smallList.move();
		smallList=null;
	}
	
	private void moveToSmall()
	{
		smallList=bigList.move();
		bigList=null;
	}
	
	public String toString()
	{
		if(smallList==null)
		{
			return ("The size of the database is "+this.size()+"\n"+bigList.toString());
		}
		else if(bigList==null)
		{
			return ("The size of the database is "+this.size()+"\n"+smallList.toString());
		}
		else
		{
			return "error";
		}
	}

	
	

}
