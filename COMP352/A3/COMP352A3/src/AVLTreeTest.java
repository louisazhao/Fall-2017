import java.util.Random;

/**
 * AVL Tree test class
 * @author zhaorui
 *
 */
public class AVLTreeTest {

	public static void main(String[] args) {
		Integer [] numbers={1,3,5,2,6,8,12,5,90,3,2,7};
		Integer [] test={6,6,6,6,6,6,6,6};
		A3AVLTree<Integer> tree=new A3AVLTree<Integer>();
		for(int i=0;i<numbers.length;i++)
		{
			tree.add(numbers[i]);
		}
		System.out.println(tree.height());
		System.out.println(tree.size());
		System.out.println();	
		System.out.println("Tree has been created!");
	
		System.out.println(tree.remove(2));		
		System.out.println(tree.remove(2));

		
		System.out.println(tree.height());
		System.out.println(tree.size());
		while(tree.iterator().hasNext())
		{
			System.out.print(tree.iterator().next()+" ");
		}
		System.out.println();
		
		//random array
		Random rand=new Random();
		Integer[] a1=new Integer[100];
		System.out.print("before sorting[");
		for(int i=0;i<a1.length;i++)
		{
			a1[i]=rand.nextInt(100);
			System.out.print(a1[i]+" ");
		}
		System.out.println("]");
		A3AVLTree<Integer> tree1=new A3AVLTree<Integer>();
		for(int i=0;i<a1.length;i++)
		{
			tree1.add(a1[i]);
		}
		System.out.println(tree1.size());
		while(tree1.iterator().hasNext())
		{
			System.out.print(tree1.iterator().next()+" ");
		}
		

	}

}
