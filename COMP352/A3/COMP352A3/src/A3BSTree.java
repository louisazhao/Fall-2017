import java.util.Collection;
import java.util.Iterator;

/**
 * 
 * binary search tree (unbalanced) generic class
 * allows duplicate key, using duplicate counter to keep track of them
 * implements Tree interface
 * @author zhaorui
 *
 * @param <E> generic class
 */
public class A3BSTree <E extends Comparable<E>> implements Tree<E>{
	
	private TreeNode<E> root;
	private BSTreeIterator<E> iterator;

	/**
	 * default constrcutor
	 */
	public A3BSTree(){
		root=null;
		iterator=null;
	}

	@Override
	/**
	 * override add function
	 * will add an element into the tree
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
	public boolean remove(Object o) 
	{
		if(root==null||!contains(root,(E)o))
		{
			return false;
		}
		else
		{
			delete(root,(E) o);
			iterator=new BSTreeIterator<E>(root);
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
	 * @param n a node
	 * @param e an element to be added
	 * @return updated node n
	 */
	private TreeNode<E> insert(TreeNode<E> n, E e)
	{
		if(n==null)
		{
			n=new TreeNode<E>(e,null,null);
		}
		else if(e.compareTo(n.getkey())<0)
		{
			n.setLeft(insert(n.getLeft(), e));
		}
		else if(e.compareTo(n.getkey())>0)
		{
			n.setRight(insert(n.getRight(), e));
		}
		else
		{
			n.increaseCounter();
		}
		return n;
	}
	
	/**
	 * helper function, delete an element from the tree (recursive)
	 * @param n a node 	
	 * @param e element to be removed
	 * @return updated node n
	 */
	private TreeNode<E> delete(TreeNode<E> n, E e)
	{
		if(n==null)
		{
			return null;
		}
		if(e.equals(n.getkey())&&n.getDuplicateCounter()==0)
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
				E smallOne=smallestInTree(n.getRight());
				n.setKey(smallOne);
				n.setRight(delete(n.getRight(),smallOne));
			}
		}
		else if(e.equals(n.getkey())&&n.getDuplicateCounter()!=0)
		{
			n.decreaseCounter();
		}
		else if(e.compareTo(n.getkey())<0)
		{
			n.setLeft(delete(n.getLeft(),e));
		}
		else
		{
			n.setRight(delete(n.getRight(),e));
		}	
		return n;
	}

	/**
	 * helper function, recursively compute the size of the subtree
	 * @param n a node
	 * @return the size of the subtree rooted at n
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
	 * @param n a node
	 * @return the next element by in-order traversal
	 */
	private E smallestInTree(TreeNode<E> n)
	{
		if(n.getLeft()==null)
		{
			return n.getkey();
		}
		else
		{
			return smallestInTree(n.getLeft());
		}
	}
	
	/**
	 * helper function,returns true if the element is in the tree
	 * @param n a node
	 * @param e an element
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
	 * @return root
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
