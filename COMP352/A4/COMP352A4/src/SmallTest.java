
public class SmallTest {

	public static void main(String[] args) {
		SmallSmartAR a=new SmallSmartAR();
		Car c1=new Car("NNNNNN",2010,"Zhang");
		Car c2=new Car("HHHHHH",2008,"Wang");
		Car c3=new Car("CCCCCC",1990,"Lee");
		Car c4=new Car("BBBBBBB",1920,"Pi");
		Car c5=new Car("AAAAAAA",1990,"Lin");
		Car c6=new Car("AAAAAAA",2000,"Huang");
		
		a.add("NNNNNN", 2010);
		a.add("HHHHHH", 2008);
		a.add("AAAAAA",1990);
		a.add("AAAAAA", 2000);
		
		System.out.println(a);
		
		a.generate(5);
		System.out.println(a);
		
//		a.remove("NNNNNN");
//		System.out.println(a.getSequence());
//		
//		a.getValues("AAAAAN");
//		a.getValues("AAAAAA");
//		
//		System.out.println(a.nextKey("AAAAAA"));
//		System.out.println(a.prevKey("AAAAAA"));
//		
//		System.out.println("all keys");
//		a.allKey();
//		
//		a.previousCars("AAAAAA");
//		

	}

}
