/**
 * TreeNode class (for binary trees)
 * a node of the tree has a key, a left child, a right child, height
 * and a duplicate counter that keep track of the number of duplicate keys
 * @author zhaorui
 *
 * @param <T> generic class
 */
public class TreeNode<T> {
	private T[] cars=(T[]) new Car[50];
	private TreeNode<T>left,right,parent;
	private int height;
	private int elementCounter;
	
	public TreeNode(T car)
	{
		this.addToArray(car);
		left=right=parent=null;
	}
	
	/**
	 * constructor
	 * @param key key value
	 * @param left left node
	 * @param right right node
	 */
	public TreeNode(T key, TreeNode<T> left, TreeNode<T> right,TreeNode<T> parent)
	{
		this.addToArray(key);
		this.left=left;
		this.right=right;
		this.parent=parent;
	}
	
	public void addToArray(T t)
	{
		cars[elementCounter]=t;
		elementCounter++;
	}
	
	/**
	 * accessor
	 * @return cars
	 */
	public T[] getElements()
	{
		return cars;
	}
	
	/**
	 * accessor
	 * @return left child
	 */
	public TreeNode<T> getLeft()
	{
		return left;
	}
	
	/**
	 * accessor
	 * @return right child
	 */
	public TreeNode<T> getRight()
	{
		return right;
	}
	
	public TreeNode<T> getParent()
	{
		return parent;
	}
	
	
	/**
	 * mutator
	 * @param newValue value to be assigned
	 */
	public void setKey(T[] newValue)
	{
		cars=newValue;
	}
	
	/**
	 * mutator
	 * @param newLeft value to be assigned
	 */
	public void setLeft(TreeNode<T> newLeft)
	{
		left=newLeft;
	}
	
	/**
	 * mutator
	 * @param newRight value to be assigned
	 */
	public void setRight(TreeNode<T> newRight)
	{
		right=newRight;
	}	
	
	public void setParent(TreeNode<T> newOne)
	{
		parent=newOne;
	}
	
	/**
	 * accessor
	 * @param n a node
	 * @return the height of the node
	 */
	public static <E> int getHeight(TreeNode<E> n)
	{
		if(n==null)
		{
			return 0;
		}
		else
		{
			int maxOfLeft=getHeight(n.getLeft());
			int maxOfRight=getHeight(n.getRight());
			if(maxOfLeft>maxOfRight)
			{
				return maxOfLeft+1;
			}
			else
			{
				return maxOfRight+1;
			}
		}
	}
	
	/**
	 * mutator
	 * @param newHeight value to be assigned
	 */
	public void setHeight(int newHeight)
	{
		this.height=newHeight;
	}
	
	/**
	 * accessor
	 * @return duplicateCounter
	 */
	public int elementCounter()
	{
		return elementCounter;
	}
	
	/**
	 * mutator
	 * @param newValue value to be assigned
	 */
	public void setDuplicateCounter(int newValue)
	{
		elementCounter=newValue;
	}
	
	/**
	 * increase the duplicateCounter by 1
	 */
//	public void increaseCounter()
//	{
//		duplicateCounter++;
//	}
//	
//	/**
//	 * decrease the duplicateCounter by 1
//	 */
//	public void decreaseCounter()
//	{
//		duplicateCounter--;
//	}
	
	public String toString()
	{
		String s="There are "+elementCounter+" cars registered under this plate, which are:\n";
		for(int i=0;i<elementCounter;i++)
		{
			s+=cars[i]+"\n";
		}
		return s;
	}
}
