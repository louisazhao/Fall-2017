import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.math.BigInteger;

/**COMP 352 SectionG fall semester 2017
 * Assignment 1 programming part
 * Calculate the Tetranacci series using quaternary recursive function.
 * @author zhaorui
 * Student ID:40018813
 */
public class QuaternaryTet {

	public static void main(String[] args)
	//main method, calls exponential versions of tetranacci calculator,
	//record runtime and write them into file "out.txt".
	{
		PrintWriter outputStream=null;
		try{
			outputStream=new PrintWriter(new FileOutputStream("out.txt"));
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Error opening the file out.txt");
			System.exit(0);
		}
		
		System.out.println("Will run binaryTet and linearTet and record the runtime in the txt file." );
		outputStream.println("Runtime records for the quaternary tetranacci method:");
		for(int i=5;i<=35;i+=5) //only test quaternaryTet until n=35.After that, the runtime is too long.
		{
			long timeStart=System.nanoTime();//record the time before function execution
			BigInteger result=quaternaryTet(i);//make function call
			long timeEnd=(System.nanoTime()-timeStart);//calculate eclipsed time
			System.out.println("Tetranacci("+i+") is "+result);
			outputStream.println("Tetranacci("+i+") is "+result);//write the result to file
			System.out.println("Runing binaryTet("+i+") takes "+timeEnd+ " nanoseconds.");
			outputStream.println("Runing binaryTet("+i+") takes "+timeEnd+ " nanoseconds.");	//write runtime to file		
		}
		outputStream.close();
	}
		
	public static BigInteger quaternaryTet(int n)
	//quaternaryTet method,will call itself four times in the body
	{
		if (n<=2) //when n=0,1,2, 0 will be returned.
		{
			return BigInteger.ZERO;
		}
		else if (n==3) //when n=3, 1 will be returned.
		{
			return BigInteger.ONE;
		}
		else//if n>3, add the previous 4 elements
		{
			return quaternaryTet(n-1).add(quaternaryTet(n-2)).add(quaternaryTet(n-3)).add(quaternaryTet(n-4));
		}
	}
}
