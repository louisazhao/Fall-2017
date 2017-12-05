import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;

/**
 * driver class
 * @author zhaorui
 *
 */
public class SortTester {
	
	static final int[] numberOfLengths={10,100,1000,10000,100000,1000000};
	
	public static void main(String[] args) {
		Tree <Integer> BStree = new A3BSTree<Integer>();
		Integer temp[];
		long timeStart,timeEnd;
		
		PrintWriter outputStream=null;
		try{
			outputStream=new PrintWriter(new FileOutputStream("testrun.txt"));
		}
		catch(FileNotFoundException excep)
		{
			System.out.println("Error opening the file testrun.txt");
			System.exit(0);
		}
		
		for(int i=0;i<numberOfLengths.length;i++)
		{
			System.out.println("N = "+numberOfLengths[i]+":");
			outputStream.println("N = "+numberOfLengths[i]+":");
			Integer[] a=new Integer[numberOfLengths[i]];
			
			//unsorted, shuffled array
			createShuffleArray(a);	
			temp=copyArray(a);
			timeStart=System.nanoTime();
			TreeSort.sort(BStree, a);
			timeEnd=(System.nanoTime()-timeStart);
			System.out.println("BST                  "+timeEnd+" nanoseconds");
			outputStream.println("BST                  "+timeEnd+" nanoseconds");
			((A3BSTree<Integer>) BStree).clear();
			//AVLTree sorting ends when N=100000
			if(i<4)
			{
				timeStart=System.nanoTime();
				TreeSort.sort(temp);
				timeEnd=(System.nanoTime()-timeStart);
				System.out.println("AVL                  "+timeEnd+" nanoseconds");
				outputStream.println("AVL                  "+timeEnd+" nanoseconds");
			}
			
			//reverse-order array 
			//ends when N=100000 (for both BSTree and AVLTree)			
			if(i<4)
			{
				createReverseArray(a);
				temp=copyArray(a);
				timeStart=System.nanoTime();
				TreeSort.sort(BStree, a);
				timeEnd=(System.nanoTime()-timeStart);
				System.out.println("BST(rev-sorted)      "+timeEnd+" nanoseconds");
				outputStream.println("BST(rev-sorted)      "+timeEnd+" nanoseconds");
				((A3BSTree<Integer>) BStree).clear();
				timeStart=System.nanoTime();
				TreeSort.sort(temp);
				timeEnd=(System.nanoTime()-timeStart);
				System.out.println("AVL(rev-sorted)      "+timeEnd+" nanoseconds");
				outputStream.println("AVL(rev-sorted)      "+timeEnd+" nanoseconds");
				outputStream.println();
			}
			System.out.println();
			
		}
		outputStream.close();
	}
	
	/**
	 * initialize an array and then shuffle the content of an array
	 * @param a an array
	 */
	public static void createShuffleArray(Integer[] a)
	{
		for (int i = 0; i < a.length; i++){
			a[i] = i;
		}
		Collections.shuffle(Arrays.asList(a));
//		System.out.printf("Shuffled Array%n%s%n",Arrays.toString(a));
	}
	
	/**
	 * initialize an array with its elements corresponding to its index
	 * and then reverse the array
	 * @param a an array
	 */
	public static void createReverseArray(Integer[] a)
	{
		for (int i = 0; i < a.length; i++){
			a[i] = i;
		}
		Stack<Integer> temp=new Stack<Integer>();
		for(int i=0;i<a.length;i++)
		{
			temp.push(a[i]);
		}
		int i=0;
		while(!temp.isEmpty())
		{
			a[i]=temp.pop();
			i++;
		}
//		System.out.printf("Reversed Array%n%s%n",Arrays.toString(a));
	}
	
	/**
	 * copy the content of an array into a new array
	 * @param a array to be copied
	 * @return a new array
	 */
	public static Integer[] copyArray(Integer[] a)
	{
		Integer[] result=new Integer[a.length];
		for(int i=0;i<a.length;i++)
		{
			result[i]=a[i];
		}
		return result;
	}
}
