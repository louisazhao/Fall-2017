import java.util.Collection;
import java.util.Iterator;
import java.lang.Math;

/**
 * @author zhaorui
 * AVL tree (balanced binary search tree) generic class
 * allows duplicate key, using duplicate counter to keep track of them
 * implements Tree interface
 *
 */
public class A3AVLTree <E extends Comparable<E>> implements Tree<E>{

	private TreeNode<E> root;
	private BSTreeIterator<E> iterator;

	/**
	 * default constructor 
	 */
	public A3AVLTree(){
		root=null;
		iterator=null;
	}
	
	@Override
	/**
	 * override add function
	 * will add an element into the tree
	 * 
	 */
	public void add(E e) {
		root=insert(root,e);
		iterator=new BSTreeIterator<E>(root);//update iterator
	}

	@Override
	/**
	 * override addAll function
	 * will add a collection of elements into the tree
	 */
	public void addAll(Collection<? extends E> c) {
		for (Iterator<? extends E> iterator = c.iterator(); iterator.hasNext();) {
			E element = iterator.next();
			add(element);
		}
		iterator=new BSTreeIterator<E>(root);//update iterator
	}

	@Override
	/**
	 * override remove function
	 * return true if the remove is done successfully
	 */
	public boolean remove(Object o) {
		System.out.println("Trying to remove the value");
		if(root==null||!contains(root,(E)o))
		{
			System.out.println("Removel failed!");
			return false;
		}
		else
		{
			delete(root,(E) o);
			System.out.println("Value has been removed from tree.");
			iterator=new BSTreeIterator<E>(root);//update iterator
			return true;
		}
	}

	@Override
	/**
	 * override Iterator function
	 * return an iterator of the tree
	 */
	public Iterator<E> iterator() {
		return iterator;
	}

	@Override
	/**
	 * override height function
	 * will return the height of the tree
	 */
	public int height() {
		return TreeNode.getHeight(root);
	}

	@Override
	/**
	 * override size function
	 * will return the number of elements of the tree
	 */
	public int size() {
		return computeSize(root);
	}
	
	/**
	 * helper function, insert an element into the tree (recursive)
	 * @param n a node of the tree
	 * @param e element that will be inserted
	 * @return updated node n
	 */
	private TreeNode<E> insert(TreeNode<E> n, E e)
	{
		if(n==null)
		{
//			System.out.println("add to root");
			n = new TreeNode<E>(e,null,null);
		}
		else if (e.compareTo(n.getkey())<0)
		{
//			System.out.println("first loop");
			n.setLeft(insert(n.getLeft(), e));
			if(TreeNode.getHeight(n.getLeft())-TreeNode.getHeight(n.getRight())==2)
			{
//				System.out.println("NOT BALANCE, LEFT IS HIGHER");
				if(e.compareTo(n.getLeft().getkey())<0)
				{
//					System.out.println("single left");
					n=singleRotateLeft(n);
				}
				else
				{
//					System.out.println("double left");
					n=doubleRotateLeft(n);
				}
			}		
		}
		else if (e.compareTo(n.getkey())>0)
		{
//			System.out.println("second loop");
			n.setRight(insert(n.getRight(), e));
			if(TreeNode.getHeight(n.getRight())-TreeNode.getHeight(n.getLeft())==2)
			{
//				System.out.println("NOT BALANCE, RIGHT IS HIGHER");
				if(e.compareTo(n.getRight().getkey())>0)
				{
//					System.out.println("single right");
					n=singleRotateRight(n);
				}
				else
				{
//					System.out.println("double right");
					n=doubleRotateRight(n);
				}
			}
		}
		else
		{
			n.increaseCounter();
		}
		n.setHeight(Math.max(TreeNode.getHeight(n.getLeft()), TreeNode.getHeight(n.getRight()))+1);
		return n;
	}
	
	/**
	 * helper function, delete an element from the tree (recursive)
	 * @param n a node of the tree
	 * @param e element to delete
	 * @return updated node n
	 */
	private TreeNode<E> delete(TreeNode<E> n, E e)
	{
		if(n==null)
		{
			n=null;
		}
		if(e.equals(n.getkey()))//find the element we want to remove
		{
			if(n.getDuplicateCounter()!=0)//duplicate keys
			{
				n.decreaseCounter();//only decrease the counter
			}
			else//not duplicate, remove the node
			{
				if(n.getLeft()==null&&n.getRight()==null)
				{
					n=null;
				}
				else if(n.getLeft()==null)
				{
					n=n.getRight();
				}
				else if(n.getRight()==null)
				{
					n=n.getLeft();
				}
				else
				{
//					System.out.println("MODIFICATION");
					TreeNode<E> smallOne=smallestInTree(n.getRight());
					n.setKey(smallOne.getkey());
					n.setDuplicateCounter(smallOne.getDuplicateCounter());
					smallOne.setDuplicateCounter(0);
					n.setRight(delete(n.getRight(),smallOne.getkey()));
				}
			}
		}
		else if(e.compareTo(n.getkey())<0)
		{
			n.setLeft(delete(n.getLeft(),e));
		}
		else
		{
			n.setRight(delete(n.getRight(),e));
		}
//		System.out.println("before balancing");
//		TreePrinter.printNode(n);
		
		if(n==null)
		{
			return null;
		}	
		n.setHeight(Math.max(TreeNode.getHeight(n.getLeft()),TreeNode.getHeight(n.getRight()))+1);
		
		if(getBalanceFactor(n)>1)//left subtree is higher
		{
			if(getBalanceFactor(n.getLeft())>=0)//left child of the left subtree is higher
			{
				return singleRotateLeft(n);
			}
			else
			{
				return doubleRotateLeft(n);
			}
		}
		if(getBalanceFactor(n)<-1)//right subtree is higher
		{
			if(getBalanceFactor(n.getRight())<=0)//right child of the right subtree is higher
			{
				return singleRotateRight(n);
			}
			else
			{
				return doubleRotateRight(n);
			}
		}
		return n;
	}
	
	/**
	 * helper function, calculate the difference of the heights between left subtree 
	 * and right subtree
	 * @param n a node of tree
	 * @return difference in heights
	 */
	private static <E> int getBalanceFactor(TreeNode<E> n)
	{
		if(n==null)
			return 0;
		else
			return (TreeNode.getHeight(n.getLeft())-TreeNode.getHeight(n.getRight()));
	}
	
	/**
	 * single rotate left child
	 * @param k2 a node 
	 * @return the node that has been rotated as the root of the subtree
	 */
	private TreeNode<E> singleRotateLeft(TreeNode<E> k2)
	{
		TreeNode<E> k1=k2.getLeft();
		k2.setLeft(k1.getRight());
		k1.setRight(k2);
		k2.setHeight(Math.max(TreeNode.getHeight(k2.getLeft()), TreeNode.getHeight(k2.getRight()))+1);
		k1.setHeight(Math.max(TreeNode.getHeight(k1.getLeft()), TreeNode.getHeight(k2))+1);
		if(k2==root)
		{
			root=k1;
		}
		return k1;
	}
	
	/**
	 * single rotate right child
	 * @param k1 a node
	 * @return the node that has been rotated as the root of the subtree
	 */
	private TreeNode<E> singleRotateRight(TreeNode<E> k1)
	{
		TreeNode<E> k2=k1.getRight();
		k1.setRight(k2.getLeft());
		k2.setLeft(k1);
		k1.setHeight(Math.max(TreeNode.getHeight(k1.getLeft()), TreeNode.getHeight(k1.getRight()))+1);
		k2.setHeight(Math.max(TreeNode.getHeight(k2.getRight()), TreeNode.getHeight(k1))+1);
		if(k1==root)
		{
			root=k2;
		}
		return k2;
	}
	
	/**
	 * double rotate left child
	 * @param k3 a node
	 * @return updated node
	 */
	private TreeNode<E> doubleRotateLeft(TreeNode<E> k3)
	{
//		System.out.println("double left");
		k3.setLeft(singleRotateRight(k3.getLeft()));
		return singleRotateLeft(k3);
	}
	
	/**
	 * double rotate right child
	 * @param k1 a node
	 * @return updated node
	 */
	private TreeNode<E> doubleRotateRight(TreeNode<E> k1)
	{
//		System.out.println("double right");
		k1.setRight(singleRotateLeft(k1.getRight()));
		return singleRotateRight(k1);
	}
	
	/**
	 * helper function, recursively compute the size of the subtree
	 * @param n a node
	 * @return the number of elements in the subtree
	 */
	private int computeSize(TreeNode<E> n)
	{
		if(n==null)
		{
			return 0;
		}
		else 
		{
			return 1+n.getDuplicateCounter()+computeSize(n.getLeft())+computeSize(n.getRight());
		}
	}
	
	/**
	 * helper function, finds the next element in in-order traversal
	 * @param n
	 * @return the next element by in-order traversal
	 */
	private TreeNode<E> smallestInTree(TreeNode<E> n)
	{
		if(n.getLeft()==null)
		{
			return n;
		}
		else
		{
			return smallestInTree(n.getLeft());
		}
	}
	
	/**
	 * helper function,returns true if the element is in the tree
	 * @param n a node
	 * @param e an element to be found
	 * @return true if the element is in the tree
	 */
	private boolean contains(TreeNode<E> n, E e)
	{
		if(n==null)
		{
			System.out.println("Key "+e+" doesn't exist in the tree.");
			return false;
		}
		else if(e.compareTo(n.getkey())<0)
		{
			return contains(n.getLeft(),e);
		}
		else if(e.compareTo(n.getkey())>0)
		{
			return contains(n.getRight(),e);
		}
		return true;
	}

	/**
	 * accessor
	 * @return the root
	 */
	protected TreeNode<E> getRoot()
	{
		return root;
	}
	
	/**
	 * clear the tree
	 */
	protected void clear()
	{
		this.root=null;
		this.iterator=null;
	}
	

}
