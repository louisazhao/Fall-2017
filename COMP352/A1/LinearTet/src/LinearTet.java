import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.math.BigInteger;

/**COMP 352 SectionG fall semester 2017
 * Assignment 1 programming part
 * Calculate the tetranacci series using linear recursive function.
 * @author zhaorui
 * Student ID:40018813
 */
public class LinearTet {
		public static void main(String[] args)
		//main method, calls linear version of tetranacci calculator,
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
			
			System.out.println("Will run linearTet and record the runtime in the txt file." );			
			outputStream.println("Runtime records for the linear tetranacci method:");
			for(int i=5;i<=100;i+=5)
			{
				long timeStart1=System.nanoTime();//record the time before function execution
				BigInteger result1=linearTet(i)[0];//make function call
				long timeEnd1=(System.nanoTime()-timeStart1);//calculate eclipsed time
				System.out.println("Tetranacci("+i+") is "+result1);
				outputStream.println("Tetranacci("+i+") is "+result1);//write the result to file
				System.out.println("Runing binaryTet("+i+") takes "+timeEnd1+ " nanoseconds.");
				outputStream.println("Runing binaryTet("+i+") takes "+timeEnd1+ " nanoseconds.");//write runtime to file				
			}
			
			outputStream.close();
		}
		
		public static BigInteger[] linearTet(int n)
		//linearTet method, will call itself only once in the body
		{
			BigInteger array[]={BigInteger.ZERO,BigInteger.ZERO,BigInteger.ZERO,BigInteger.ZERO};
			//create an array to store values, the first element of the array will be the result
			if(n<=2)//when n=0,1,2, the first element is 0.
			{
				return array;
			}
			else if(n==3)//when n=3, the first element is 1.
			{
				array[0]=BigInteger.ONE;
				return array;
			}
			else//when n>3, the function will call itself, and the first element of the 
				//array will be the sum of all elements of the array that is returned by
				//the one it calls.
			{
				array=linearTet(n-1);
				BigInteger result[]={(array[0].add(array[1]).add(array[2]).add(array[3])),array[0],array[1],array[2]};
				return result;
			}
			
		}
		

}
