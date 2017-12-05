import java.util.Iterator;
import java.util.Stack;

/**
 * Iterator class for binary tree (works for unbalanced and balanced binary tree)
 * allows duplicate keys
 * @author zhaorui
 *
 * @param <E> generic class
 */
public class BSTreeIterator<E> implements Iterator<E>{
	Stack<TreeNode<E>> stackOfNode;
	
	/**
	 * default constructor
	 * @param n create an iterator starts from node n
	 */
	public BSTreeIterator(TreeNode<E> n)
	{
		stackOfNode=new Stack<TreeNode<E>>();
		while(n!=null)
		{
			
			stackOfNode.push(n);
			n=n.getLeft();
		}	
	}

	@Override
	/**
	 * override hasNext function
	 * return true if the tree has another node
	 */
	public boolean hasNext() {
		return !stackOfNode.isEmpty();
	}

	@Override
	/**
	 * override next function
	 * returns the next node in the tree by in-order traversal
	 * consider the duplicate case
	 */
	public E next() {
		E result;
		TreeNode<E> temp;
		temp=stackOfNode.peek();
		if(temp.getDuplicateCounter()!=0)
		{
			result=temp.getkey();
			temp.decreaseCounter();
		}
		else
		{
			stackOfNode.pop();
			result=temp.getkey();
			if(temp.getRight()!=null)
			{
				temp=temp.getRight();
				while(temp!=null)
				{
					stackOfNode.push(temp);
					temp=temp.getLeft();
				}
			}
		}
		return result;
	}
}
