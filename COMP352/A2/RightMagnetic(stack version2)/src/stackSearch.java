import java.util.Random;

public class stackSearch {

	public static void main(String[] args) {
		int[] array1={10,4,3,6,5,7,0};//normal case, true
		int[] array2={1,10,16,4,6,2,10,0};//bounce on the two "10"
		int[] array3={11,8,3,2,1,6,10,0};//infinite loop, jump back and forth
		int[] array4={8,16,10,4,6,10,2,12,8,11,8,3,2,1,6,10,0};//complete infinite loop
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
//		size=rand.nextInt(1000000)+1;//test for a random array with size 1 to 100000
//		test=generatingArray(size);
////		display(test,0);
	}
	
	
	public static boolean stackRightMagnetic(int[]a, int marker)
	{
		if(marker>(a.length-1))//if the given start marker is bigger than the size, return false
		{
			return false;
		}
		ArrayStack<Integer> s1=new ArrayStack<Integer>(a.length);//stack that stores visited index
		ArrayStack<Integer> s2=new ArrayStack<Integer>(a.length);//stack that works as a temporary storage
		int temp;
		s1.push(marker);//move to the start marker
		while(marker!=a.length-1)//while not solved
		{
			temp=a[s1.top()]/2+(a[s1.top()]%2==0?0:1);
			int rightIndex=marker+temp;//potential index to the right
			int leftIndex=marker-temp;//potential index to left
			if(rightIndex<a.length)//check if right index is in bound, if so move to right
			{
				s1.push(rightIndex);//move to right
				marker=rightIndex;//now the marker is at the new position
			}
			else if(leftIndex>0)//when it's impossible to move to right and if left index is in bound,then
			{
				for(int i=0;i<s1.size();i++)
				{
					if(leftIndex==s1.top())
					//compare potential left index with every index stored in s1, if found duplicate, return false
					{
						return false;
					}
					s2.push(s1.pop());//move the compared index in s1 to s2 in order to compare the next one			
				}
				//if the potential left index is not visited
				for(int i=0;i<s2.size();i++)
				{
					s1.push(s2.pop());//move elements back to s1
				}
				s1.push(leftIndex);//move to left
				marker=leftIndex;//now the marker is at the new position
			}
			else
				return false;//out of bound, return false
		}
		return true;//array is solvable
	}
	

	public static void display(int[] a, int x)
	{
		System.out.println("The right magnetic result for array ");
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i]+" ");
		}
		System.out.println("\nwith size "+a.length+" and start marker "+x+" is "+stackRightMagnetic(a, x));
		System.out.println();
	}
	
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
