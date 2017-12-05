/*
 * helper class, self-defined stack using array implementation
 */
public class ArrayStack<E> {
	private E[] data;
	private int top=-1;
	
	/*
	 * constructor
	 */
	public ArrayStack(int capacity)
	{
		data=(E[])new Object[capacity];	
	}
	
	/*
	 * pop
	 */
	public E pop()
	{
		if (isEmpty())
		{
			System.out.println("Cannot pop, stack is empty");
			return null;
		}
		E temp=data[top];
		data[top]=null;
		top--;
		return temp;			
	}
	
	/*
	 * push
	 */
	public void push(E e)
	{
		if(size()==data.length)
		{
			System.out.println("Cannot push, stack is full");
		}
		data[++top]=e;
	}
	
	/*
	 * top
	 */
	public E top()
	{
		if (isEmpty())
		{
			System.out.println("Cannot read the top, stack is empty");
			return null;
		}
		return data[top];
	}
	
	/*
	 * isEmpty
	 */
	public boolean isEmpty()
	{
		return(top==-1);
	}
	
	/*
	 * size
	 */
	public int size()
	{
		return top+1;
	}

}
