

public class Sequence <E extends Comparable<E>> {
	//innner class
	public class DLLNode<E> implements Position<E>{
		private E[] cars=(E[]) new Car[50];
		//assume we can only have at most 50 cars registered under one plate
		private DLLNode<E> next;
		private DLLNode<E> prev;
		private int elementCounter;
		
		public DLLNode()
		{
			next=null;
			prev=null;
			elementCounter=0;
		}
		public DLLNode(E data, DLLNode<E> next, DLLNode<E> prev)
		{
			addToArray(data);
			this.next=next;
			this.prev=prev;
		}
		@Override
		public E[] getElements(){return this.cars;}
		public DLLNode<E> getPrev(){return prev;}
		public DLLNode<E> getNext(){return next;}
		public void setElement(E[] e){cars=e;}
		public void setNext(DLLNode<E> n){next=n;}
		public void setPrev(DLLNode<E> n){prev=n;}
		public int getElementCounter() {return elementCounter;}
		public void addToArray(E e)
		{
			cars[elementCounter]=e;
			elementCounter++;
		}
//		public String getPlate()
//		{
//			Car temp=(Car)cars[0];
//			return temp.getLicensePlate();
//		}
		
		public String toString()
		{
			String s="There are "+elementCounter+" cars registered under this plate, which are:\n";
			for(int i=0;i<elementCounter;i++)
			{
				s+=cars[i]+"\n";
			}
			return s;
		}
		
		public int compareTo(DLLNode<E> another)
		{
			Car temp=(Car)this.getElements()[0];
			Car compared=(Car)another.getElements()[0];
			return temp.getLicensePlate().compareTo(compared.getLicensePlate());
		}
	}
	
	//sequence class
	private DLLNode<E> header;
	private DLLNode<E> trailer;
	private int size=0;
	
	public Sequence()
	{
		size=0;
		header=new DLLNode<>(null,null,null);
		trailer=new DLLNode<>(null,header,null);
		header.next=trailer;
	}
	
	private DLLNode<E> validate(Position<E> p)//exception
	{
		if(!(p instanceof DLLNode)){System.out.println("Invalid p");}
		DLLNode<E> node=(DLLNode<E>)p;
		if(node.getNext()==null)
		{
			System.out.println("p is no longer in the list");
		}
		return node;	
	}
	
	private Position<E> position(DLLNode<E> node)
	{
		if(node==header||node==trailer)
			return null;
		return node;
	}
	
	//generic methods
	public int size(){return size;}
	
	public boolean isEmpty(){return (size==0);}
	
	//node list functions
	public Position<E> first()
	{
		return position(header.next);
	}
	
	public Position<E> last()
	{
		return position(trailer.prev);
	}
	
	public Position<E> prev(Position<E> p)
	{
		DLLNode<E> node=validate(p);
		return position(node.getPrev());
	}
	
	public Position<E> next(Position<E> p)
	{
		DLLNode<E> node=validate(p);
		return position(node.getNext());
	}
	
	public Position<E> addFirst(E e)
	{
		DLLNode<E> newNode=new DLLNode<E>(e,null,null);
		if(this.isEmpty())
		{
			newNode.setPrev(header);
			newNode.setNext(trailer);
			header.setNext(newNode);
			trailer.setPrev(newNode);
		}
		else
		{
			DLLNode<E> temp=header.getNext();
			newNode.setPrev(header);
			newNode.setNext(temp);
			temp.setPrev(newNode);
			header.setNext(newNode);
		}
		size++;
		return newNode;
	}
	
	public Position<E> addLast(E e)
	{
		DLLNode<E> newNode=new DLLNode<>(e,null,null);
		if(this.isEmpty())
		{
			newNode.setPrev(header);
			newNode.setNext(trailer);
			header.setNext(newNode);
			trailer.setPrev(newNode);
		}
		else
		{
			DLLNode<E> temp=trailer.getPrev();
			newNode.setPrev(temp);
			newNode.setNext(trailer);
			trailer.setPrev(newNode);
			temp.setNext(newNode);
		}
		size++;
		return newNode;
	}
	
	public Position<E> addBefore(Position<E> p, E e)
	{
		DLLNode<E> node=validate(p);
		DLLNode<E> prevNode=node.getPrev();
		DLLNode<E> newNode=new DLLNode<E>(e,null,null);
		newNode.setPrev(prevNode);
		newNode.setNext(node);
		prevNode.setNext(newNode);
		node.setPrev(newNode);
		size++;
		return newNode;
	}
	
	public Position<E> addAfter(Position<E> p, E e)
	{
		DLLNode<E> node=validate(p);
		DLLNode<E> nextNode=node.getNext();
		DLLNode<E> newNode=new DLLNode<E>(e,null,null);
		newNode.setPrev(node);
		newNode.setNext(nextNode);
		node.setNext(newNode);
		nextNode.setPrev(newNode);
		size++;
		return newNode;
	}
	
	//duplicate key
	public void addToSameKey(Position<E>p, E e)
	{
		DLLNode<E> node=validate(p);
		node.addToArray(e);
	}
	
	//sort the cars under same plate using reverse order
	public void sortPlate(Position<E> p)
	{
		DLLNode<E> node=validate(p);
		for(int i=0;i<node.getElementCounter();i++)
		{
			for(int j=1;j<node.getElementCounter()-i;j++)
			{
				if(p.getElements()[j-1].compareTo(p.getElements()[j])<0)//reverse order
				{
					Car temp=(Car) p.getElements()[j-1];
					p.getElements()[j-1]=p.getElements()[j];
					p.getElements()[j]=(E) temp;
				}
			}
		}	
	}
	
	
	public E[] set(Position<E> p, E[] e)
	{
		DLLNode<E> node=validate(p);
		E[] replaced=node.getElements();
		node.setElement(e);
		return replaced;
	}
	
	public E[] remove(Position<E> p)
	{
		DLLNode<E> node=validate(p);
		DLLNode<E> predecessor=node.getPrev();
		DLLNode<E> successor=node.getNext();
		predecessor.setNext(successor);
		successor.setPrev(predecessor);
		size--;
		E[] result=node.getElements();
		node.setElement(null);
		node.setPrev(null);
		node.setNext(null);
		return result;
	}
	
	//bridge functions
	public int indexOf(Position<E> p)
	{
		DLLNode<E> node=validate(p);
		if(node==header.getNext())
		{
			return 0;
		}
		else
		{
			return (1+indexOf(node.getPrev()));
		}
	}
	
	public Position<E> atIndex(int i)
	{
		if(this.isEmpty()||i>size-1)
		{
			return null;
		}
		DLLNode<E> result=header.getNext();
		for(int k=0;k<i;k++)
		{
			result=result.getNext();
		}
		return result;	
	}
	
	
	//arraylist functions
	public E[] get(int i)
	{
		Position<E> position=atIndex(i);
		if(position==null)
		{
			return null;
		}
		else
		{
			return position.getElements();
		}
	}
	
	public void set(int i, E[] e)
	{
		Position<E> position=atIndex(i);
		DLLNode<E> node=validate(position);
		if(node!=null)
		{
			node.setElement(e);
		}
	}
	
	public Position<E> add(int i, E e)
	{
		Position<E> newPosition;
		if(i==0)
		{
			newPosition=addFirst(e);
		}
		else if(i==size)
		{
			newPosition=addLast(e);
		}
		else
		{
			Position<E> position=atIndex(i);//will be null if the sequence is empty or the index is out of bound
			if(position==null)
			{
				newPosition=null;
			}
			else
			{
				DLLNode<E> prev=validate(position).getPrev();
				newPosition=addAfter(prev,e);
			}
		}
		return newPosition;	
	}
	
	public E[] remove(int i)
	{
		Position<E> newPosition=atIndex(i);//null if empty or out of bound
		if(newPosition==null)
		{
			System.out.println("No item has been moved.");
			return null;
		}
		return remove(newPosition);	
	}
	
	public String toString()
	{
		String s="";
		DLLNode<E> temp=header.getNext();
		if(this.isEmpty())
		{
			s="No item in the sequence.";
		}
		else
		{
			while(temp!=trailer)
			{
				s+="There are "+temp.getElementCounter()+" items with same key, which are:\n";
				for(int i=0;i<temp.getElementCounter();i++)
				{
					s+=temp.getElements()[i]+"\n";
				}
			//	s+=temp.getElements()+"\n";
				temp=temp.getNext();
			}
		}
		return s;
	}
	

	
	public void sortedAdd(Car c)
	{
		Position<E> first=this.first();
		if(this.isEmpty())
		{
			this.addFirst((E) c);
		}
		else if(((Car) first.getElements()[0]).getLicensePlate().compareTo(c.getLicensePlate())>0)
		{
			this.addFirst((E) c);
		}
		else if(((Car) first.getElements()[0]).getLicensePlate().compareTo(c.getLicensePlate())==0)
		{
			this.addToSameKey(first, (E)c);
		}
		else
		{
			Position<E> next=this.next(first);
			while(next!=null&&((Car) next.getElements()[0]).getLicensePlate().compareTo(c.getLicensePlate())<0)
			{
				first=next;
				next=this.next(next);
			}
			this.addAfter(first, (E) c);
		}
	}
	   
}
