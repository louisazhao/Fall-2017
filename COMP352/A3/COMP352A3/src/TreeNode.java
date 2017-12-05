/**
 * TreeNode class (for binary trees)
 * a node of the tree has a key, a left child, a right child, height
 * and a duplicate counter that keep track of the number of duplicate keys
 * @author zhaorui
 *
 * @param <T> generic class
 */
public class TreeNode<T> {
	private T key;
	private TreeNode<T>left,right;
	private int height;
	private int duplicateCounter;
	
	/**
	 * constructor
	 * @param key key value
	 * @param left left node
	 * @param right right node
	 */
	public TreeNode(T key, TreeNode<T> left, TreeNode<T> right)
	{
		this.key=key;
		this.left=left;
		this.right=right;
		duplicateCounter=0;
	}
	
	/**
	 * accessor
	 * @return key
	 */
	public T getkey()
	{
		return key;
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
	
	/**
	 * mutator
	 * @param newValue value to be assigned
	 */
	public void setKey(T newValue)
	{
		key=newValue;
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
	public int getDuplicateCounter()
	{
		return duplicateCounter;
	}
	
	/**
	 * mutator
	 * @param newValue value to be assigned
	 */
	public void setDuplicateCounter(int newValue)
	{
		duplicateCounter=newValue;
	}
	
	/**
	 * increase the duplicateCounter by 1
	 */
	public void increaseCounter()
	{
		duplicateCounter++;
	}
	
	/**
	 * decrease the duplicateCounter by 1
	 */
	public void decreaseCounter()
	{
		duplicateCounter--;
	}
}
