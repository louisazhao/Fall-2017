import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Driver {

	public static void main(String[] args) {
		SmartAR database=new SmartAR();
		database.add("NNNNNN", 2010);
		database.add("HHHHHH", 2008);
		database.add("AAAAAA",1990);
		database.add("AAAAAA", 2000);
		database.add("DFA325", 2001);
		database.add("HHHHHH", 1990);
		database.add("324GDQ", 1998);

		
		database.generate(5);
		System.out.println(database);
		database.getValues("AAAAAN");
		database.getValues("AAAAAA");
		System.out.println(database.previousCars("AAAAAA"));
		
		database.remove("AAAAAA");
		database.remove("NNNNNN");
		database.remove("HHHHHH");
		database.remove("324GDQ");
		database.remove("DFA325");
		System.out.println(database);

		System.out.println("---------------------------");
		System.out.println("all keys");
		System.out.println("---------------------------");
		database.allKey();
		System.out.println("\n\n");
		
//		Scanner inputStream=null;
//		try{
//			inputStream=new Scanner(new FileInputStream("ar_test_file1.txt"));
//		}
//		catch(FileNotFoundException e)
//		{
//			System.out.println("Cannott open the file.");
//			System.exit(0);
//		}
//		SmartAR test1=new SmartAR();
//		String line=null;
//		while(inputStream.hasNextLine())
//		{
//			line=inputStream.nextLine();
//			test1.add(line, 0);
//		}
//		inputStream.close();
//		System.out.println(test1);
	}

}
