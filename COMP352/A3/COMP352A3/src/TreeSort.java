import java.util.Arrays;
import java.util.Iterator;

/**
 * TreeSort class
 * @author zhaorui
 *
 */
public class TreeSort{
	/** Sorts an array using TreeSort with a balanced BST implementation 
	 * @param a an array to sort
	 */
	public static <E extends Comparable<E>> void sort(E[] a){
		System.out.println("using AVL tree for sorting.");
		Tree <E> tree = new A3AVLTree<E>();
		for(int i=0;i<a.length;i++)
		{
			tree.add(a[i]);
		}
		int i=0;
		while(tree.iterator().hasNext())
		{
			a[i]=tree.iterator().next();
			i++;
		}
//		System.out.printf("Sorted%n%s%n",Arrays.toString(a));
//		TreePrinter.printNode(((A3AVLTree<E>) tree).getRoot());
	}
	
	/**
	 * Sorts an array using TreeSort with a specified BST
	 * @param tree tree to use
	 * @param a an array to sort
	 */
	public static <E> void sort(Tree <E> tree, E[] a){
		System.out.println("Using "+tree.getClass()+" for sorting." );
		for(int i=0;i<a.length;i++)
		{
			tree.add(a[i]);
		}
		int i=0;
		while(tree.iterator().hasNext())
		{
			a[i]=tree.iterator().next();
			i++;
		}
//		System.out.printf("Sorted%n%s%n",Arrays.toString(a));
	}
}
