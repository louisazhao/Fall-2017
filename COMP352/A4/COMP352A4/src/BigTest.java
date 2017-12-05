
public class BigTest {

	public static void main(String[] args) {
		BigSmartAR a=new BigSmartAR();
		a.add("NNNNNN", 2010);
		a.add("HHHHHH", 2008);
		a.add("AAAAAA",1990);
		a.add("AAAAAA", 2000);
		
		System.out.println(a);
		
		a.generate(5);
		System.out.println(a);
		
		a.remove("NNNNNN");
		System.out.println(a);
		
		a.getValues("AAAAAN");
		a.getValues("AAAAAA");
		
		System.out.println(a.nextKey("AAAAAA"));
		System.out.println(a.prevKey("AAAAAA"));
		
		System.out.println("all keys");
		a.allKey();
		
		a.previousCars("AAAAAA");
		

	}

}
