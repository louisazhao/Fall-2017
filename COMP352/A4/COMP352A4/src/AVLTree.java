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
public class AVLTree <E extends Comparable<E>>{

	private TreeNode<E> root;
	private BSTreeIterator<E> iterator;
	private int size;

	/**
	 * default constructor 
	 */
	public AVLTree(){
		root=null;
		iterator=null;
	}
	
	
	/**
	 * override add function
	 * will add an element into the tree
	 * 
	 */
	public void add(E e) {
		root=insert(root,e);
		iterator=new BSTreeIterator<E>(root);//update iterator
	}

	
	/**
	 * override addAll function
	 * will add a collection of elements into the tree
	 */
	public void addAll(Collection<? extends E> c) {
		for (Iterator<? extends E> iterator = c.iterator(); iterator.hasNext();) {
			E element = iterator.next();
			add(element);
			size++;
		}
		iterator=new BSTreeIterator<E>(root);//update iterator
	}

	
	/**
	 * override remove function
	 * return true if the remove is done successfully
	 */
	public boolean remove(String key) {
		System.out.println("Trying to remove the key "+key+"......");
		if(root==null||!contains(root,key))
		{
			System.out.println("Removel failed!");
			return false;
		}
		else
		{
			delete(root,key);
			size--;
			System.out.println("Key has been removed from tree.");
			iterator=new BSTreeIterator<E>(root);//update iterator
			return true;
		}
	}

	
	/**
	 * override Iterator function
	 * return an iterator of the tree
	 */
	public BSTreeIterator<E> iterator() {
		return iterator;
	}
	
	public void resetIterator()
	{
		this.iterator=new BSTreeIterator<E>(root);
	}

	
	/**
	 * override height function
	 * will return the height of the tree
	 */
	public int height() {
		return TreeNode.getHeight(root);
	}

	
	/**
	 * override size function
	 * will return the number of elements of the tree
	 */
	public int size() {
		return size;
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
			n = new TreeNode<E>(e,null,null,null);
			size++;
			return n;
		}
		String thisPlate=((Car)n.getElements()[0]).getLicensePlate();
		String anotherPlate=((Car)e).getLicensePlate();
		TreeNode<E> temp=null;
		if (anotherPlate.compareTo(thisPlate)<0)
		{
//			System.out.println("first loop");
			temp=insert(n.getLeft(), e);
			n.setLeft(temp);
			temp.setParent(n);
			if(TreeNode.getHeight(n.getLeft())-TreeNode.getHeight(n.getRight())==2)
			{
//				System.out.println("NOT BALANCE, LEFT IS HIGHER");
				String a=((Car)n.getLeft().getElements()[0]).getLicensePlate();
				String b=((Car)e).getLicensePlate();
				if(b.compareTo(a)<0)
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
		else if (anotherPlate.compareTo(thisPlate)>0)
		{
//			System.out.println("second loop");
			temp=insert(n.getRight(), e);
			n.setRight(temp);
			temp.setParent(n);			
			if(TreeNode.getHeight(n.getRight())-TreeNode.getHeight(n.getLeft())==2)
			{
//				System.out.println("NOT BALANCE, RIGHT IS HIGHER");
				String c=((Car)n.getRight().getElements()[0]).getLicensePlate();
				String d=((Car)e).getLicensePlate();
				if(d.compareTo(c)>0)
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
			n.addToArray(e);
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
	private TreeNode<E> delete(TreeNode<E> n, String key)
	{
		if(n==null)
		{
			n=null;
		}
		String thisPlate=((Car)n.getElements()[0]).getLicensePlate();
		if(key.equals(thisPlate))//find the element we want to remove
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
//				System.out.println("MODIFICATION");
				TreeNode<E> smallOne=smallestInTree(n.getRight());
				n.setKey(smallOne.getElements());
				n.setDuplicateCounter(smallOne.elementCounter());
				smallOne.setDuplicateCounter(0);
				n.setRight(delete(n.getRight(),((Car) smallOne.getElements()[0]).getLicensePlate()));
			}
		}
		else if(key.compareTo(thisPlate)<0)
		{
			n.setLeft(delete(n.getLeft(),key));
		}
		else
		{
			n.setRight(delete(n.getRight(),key));
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
	
	private TreeNode<E> biggestInTree(TreeNode<E> n)
	{
		if(n.getRight()==null)
		{
			return n;
		}
		else
		{
			return biggestInTree(n.getRight());
		}
	}
	
	/**
	 * helper function,returns true if the element is in the tree
	 * @param n a node
	 * @param e an element to be found
	 * @return true if the element is in the tree
	 */
	public boolean contains(TreeNode<E> n, String key)
	{
		if(n==null)
		{
			System.out.println("Key "+key+" doesn't exist in the tree.");
			return false;
		}
		String thisPlate=((Car)n.getElements()[0]).getLicensePlate();
		if(key.compareTo(thisPlate)<0)
		{
			return contains(n.getLeft(),key);
		}
		else if(key.compareTo(thisPlate)>0)
		{
			return contains(n.getRight(),key);
		}
		return true;
	}
	
	public TreeNode<E> find(TreeNode<E> n, String key)
	{
		if(n==null)
		{
			System.out.println("Key "+key+" doesn't exist in the tree.");
			return null;
		}
		String thisPlate=((Car)n.getElements()[0]).getLicensePlate();
		if(key.equals(thisPlate))
		{
			return n;
		}
		if(key.compareTo(thisPlate)<0)
		{
			return find(n.getLeft(),key);
		}
		else
		{
			return find(n.getRight(),key);
		}
	}
	
	public TreeNode<E> nextNode(TreeNode<E> n)
	{
		if(this.root==null)
		{
			return null;
		}
		TreeNode<E> next=null;
	    TreeNode<E> c = root;
	    while(c!=null && c.getElements()!=n.getElements()){
	        if(((Car) c.getElements()[0]).getLicensePlate().compareTo(((Car) n.getElements()[0]).getLicensePlate()) >0){
	            next = c;
	            c = c.getLeft();
	        }else{
	            c= c.getRight();
	        }
	    } 
	    if(c==null)        
	        return null;
	 
	    if(c.getRight()==null)
	        return next;
	 
	    c = c.getRight();
	    while(c.getLeft()!=null)
	        c = c.getLeft();
	    return c;
	}
	
	public TreeNode<E> prevNode(TreeNode<E> n)
	{
		if(n==null)
		{
			return null;
		}
		if(n.getLeft()!=null)
		{
			return biggestInTree(n.getLeft());
		}
		TreeNode<E> p=n.getParent();
		TreeNode<E> y=p;
		TreeNode<E> temp=n;
		while(p!=null&&n==p.getLeft())
		{
			temp=y;
			y=y.getParent();
		}
		return y;
		
	}
	
	public String toSting()
	{
		String s="The AVL tree has "+this.size+" keys:\n";
		while(this.iterator().hasNext())
		{
			Car[] carArray=(Car[]) this.iterator().next();
			s+="Cars registered under plate "+carArray[0].getLicensePlate()+":\n";
			for(int i=0;i<carArray.length;i++)
			{
				if(carArray[i]!=null)
				{
					s+=(carArray[i]+"\n");
				}
			}
		}
		this.iterator=new BSTreeIterator<E>(root);
		return s;
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
