/**
 * COMP 352 Assignment 2
 * Programming Part
 * Recursive version for right magnetic game
 * Rui Zhao
 * 40018813
 */

import java.util.Random;
public class RecursiveRightMagnetic {
	
	public static void main(String[] args) {
		int[] array1={8,16,10,4,6,10,2,12,8,0};//normal case, true
		int[] array2={1,10,16,4,6,2,10,0};//bounce on the two "10"
		int[] array3={11,8,3,2,1,6,10,0};//infinite loop, jump back and forth
		int[] array4={8,16,10,4,6,10,2,12,8,11,8,3,2,1,6,10,0};//complicated infinite loop
		int[] array5={2,5,1,5,7,4,6,4,8,9,14,27,0};//random		
		display(array1,0);
		display(array2,0);
		display(array3,0);
		display(array4,0);
		display(array5,0);
		
//		Random rand=new Random();
//		int size=0,marker=0;
//		int[] test;
//		for(int i=0;i<10;i++)
//		{
//			size=rand.nextInt(20)+1;//test for 10 arrays with length 1-20
//			marker=rand.nextInt(size);
//			test=generatingArray(size);
//			display(test,marker);
//		}
//		for(int i=0;i<5;i++)
//		{
//			size=rand.nextInt(50)+1;//test for 5 arrays with length 1-50
//			marker=rand.nextInt(size);
//			test=generatingArray(size);
//			display(test,marker);
//		}
//		size=rand.nextInt(100000)+1;//test for a random array with size 1 to 100000
//		test=generatingArray(size);
//		display(test,0);
//		
	}
	
	/*
	 * Algorithm of recursive version of right magnetic
	 */
	public static boolean recursiveRightMagnetic(int[] a, int startMarker)
	{
		int[]tempArray=new int[a.length];//create a new array to copy the values of original one
		for(int i=0;i<a.length;i++)
		{
			tempArray[i]=a[i];
		}
		if(startMarker>(tempArray.length-1))//if start marker is bigger than the size, return false
		{
			return false;
		}
		else if(startMarker==(tempArray.length-1))//if start marker is the last index, return true
		{
			return true;
		}
		else
		{
			int temp=tempArray[startMarker]/2+(tempArray[startMarker]%2==0?0:1);//get the increment value
			if((startMarker+temp)<=(a.length-1)&&(startMarker!=(startMarker+temp)))//check if it's in bound and if the element is visited
			{
				tempArray[startMarker]=0;//change the value of visited element to 0
				return recursiveRightMagnetic(tempArray,startMarker+temp);//move to right
			}
			else if((startMarker-temp)>0&&(startMarker!=(startMarker-temp)))//check if it's in bound and if the element is visited
			{
				tempArray[startMarker]=0;//change the value of visited element to 0
				return recursiveRightMagnetic(tempArray,startMarker-temp);//move to left
			}
			return false;
		}
	}
	
	/*
	 * helper function, display the result, is not part of the algorithm
	 */
	public static void display(int[] a, int x)
	{
		System.out.println("The right magnetic result for array ");
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i]+" ");
		}
		System.out.println("\nwith size "+a.length+" and start marker "+x+" is "+recursiveRightMagnetic(a, x));
		System.out.println();
	}
	
	/*
	 * helper function, generating random array, is not part of the algorithm
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
