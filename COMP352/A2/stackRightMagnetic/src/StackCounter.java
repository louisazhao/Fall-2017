/**
 * COMP 352 Assignment 2
 * Programming Part
 * Stack version of right magnetic game
 * Rui Zhao
 * 40018813
 */

import java.util.Random;
public class StackCounter {

	public static void main(String[] args) {
		int[] array1={10,4,3,6,5,7,0};//normal case, true
		int[] array2={1,10,16,4,6,2,10,0};//bounce on the two "10"
//		int[] array3={11,8,3,2,1,6,10,0};//infinite loop, jump back and forth
//		int[] array4={8,16,10,4,6,10,2,12,8,11,8,3,2,1,6,10,0};//complete infinite loop
		int[] array5={2,5,1,5,7,4,6,4,8,9,14,27,0};//random
		display(array1,0);
		display(array2,0);
//		display(array3,0);
//		display(array4,0);
		display(array5,0);
		
//		Random rand=new Random();
//		int size=0,marker=0;
//		int[] test;
//		for(int i=0;i<10;i++)
//		{
//			size=rand.nextInt(20)+1;//test for 10 arrays with length 1-20
//			marker=rand.nextInt(size);
//			test=generatingArray(size);
////			display(test,marker);
//		}
//		for(int i=0;i<5;i++)
//		{
//			size=rand.nextInt(50)+1;//test for 5 arrays with length 1-50
//			marker=rand.nextInt(size);
//			test=generatingArray(size);
////			display(test,marker);
//		}
//		size=rand.nextInt(1000000)+1;//test for a random array with size 1 to 100000
//		test=generatingArray(size);
//		display(test,0);
	}
	
	/*
	 * stack version of right magnetic game
	 * for a successful game, the slowest process is to visit every index once, 
	 * that’s n in total. After that, there will be repeated visit, 
	 * which means the array is unsolvable
	 */
	public static boolean counterVersion(int[]a, int marker)
	{
		if(marker>(a.length-1))//if the given start marker is bigger than the size, return false
		{
			return false;
		}
		ArrayStack<Integer> s1=new ArrayStack<Integer>(a.length);//stack that stores visited index
		int temp;
		s1.push(marker);//move to the start marker
		while(marker!=a.length-1)//while not solved
		{
			temp=a[s1.top()]/2+(a[s1.top()]%2==0?0:1);
			int rightIndex=marker+temp;//potential index to the right
			int leftIndex=marker-temp;//potential index to left
			if(rightIndex<a.length&&s1.size()<a.length)//check if right index is in bound, if so move to right
			{
				s1.push(rightIndex);//move to right
				marker=rightIndex;//now the marker is at the new position
			}
			else if(leftIndex>0&&s1.size()<a.length)//when it's impossible to move to right and if left index is in bound,then
			{
				if(s1.size()>a.length)//exceed the maximum moves for a successful game
				{
					return false;
				}
				s1.push(leftIndex);//move to right
				marker=leftIndex;//now the marker is at the new position
			}
			else return false;
		}
		return true;
	}
	
	/*
	 * helper function, display the result, not a part of algorithm
	 */
	public static void display(int[] a, int x)
	{
		System.out.println("The right magnetic result for array ");
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i]+" ");
		}
		System.out.println("\nwith size "+a.length+" and start marker "+x+" is "+counterVersion(a, x));
		System.out.println();
	}
	
	/*
	 * helper function, generate random array, not a part of algorithm
	 */
	public static int[] generatingArray(int index)
	{
		Random rand=new Random();
		int[] result=new int[index];
		int value;
		for(int i=0;i<index;i++)
		{
			value=rand.nextInt(50)+1;
			result[i]=value;
		}
		return result;
	}


}
