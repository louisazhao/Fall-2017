import java.util.Random;

/**
 * Binary search tree test class
 * @author zhaorui
 *
 */
public class BSTreeTest {

	public static void main(String[] args) {
		Integer [] numbers={1,3,5,2,6,8,12,5,90};
		Integer [] numbers2={1,3,5,2,6,8,12,5,90};
		Integer [] test={2,2,2,2,2,2,2,8,8,4};
		A3BSTree<Integer> tree1=new A3BSTree<Integer>();
		A3BSTree<Integer> tree2=new A3BSTree<Integer>();
		for(int i=0;i<test.length;i++)
		{
			tree2.add(test[i]);
		}
		System.out.println(tree2.height());
		System.out.println(tree2.size());

		System.out.println(tree2.remove(9));

		System.out.println(tree2.remove(2));

		System.out.println(tree2.height());
		System.out.println(tree2.size());
		while(tree2.iterator().hasNext())
		{
			System.out.print(tree2.iterator().next()+" ");
		}
		System.out.println();
		
		Random rand=new Random();
		Integer[] a1=new Integer[50];
		System.out.print("before sorting[");
		for(int i=0;i<a1.length;i++)
		{
			a1[i]=rand.nextInt(100);
			System.out.print(a1[i]+" ");
		}
		System.out.println("]");
		for(int i=0;i<a1.length;i++)
		{
			tree1.add(a1[i]);
		}
		while(tree1.iterator().hasNext())
		{
			System.out.print(tree1.iterator().next()+" ");
		}
	}

}
