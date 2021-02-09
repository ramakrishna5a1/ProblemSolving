class LinkedListDemo
{
	public static void main(String args[])
	{
		LinkedList ll =new LinkedList();
		Node head = null;
		
		int arr[] = {4,7,2,9,6,2};
		
		for(int i=0;i<arr.length;i++)
			head = ll.insert(head,arr[i]);
		
		ll.traverse(head);
		ll.deleteAtPosition(head,3);
		ll.traverse(head);
		
		System.out.println();		
		ll.traverse(ll.reverseListLoop(head));
	}
	
	static class Node
	{
		int data;
		Node next;
		Node prev;
		
		public Node(int data)
		{
			this.data = data;
			next = null;
			prev = null;
		}
	}
	
	
	static class LinkedList
	{
		Node insert(Node head,int data)
		{
			Node new_node =new Node(data);
			if(head == null)
				return new_node;
			
			Node temp = head;
			
			while(temp.next!=null)
				temp = temp.next;
			
			temp.next = new_node;
			new_node.prev = temp;
			
			return head;
		}
		
		void traverse(Node head)
		{
			if(head == null)
				return;
			
			System.out.println("FORWARD");
			Node temp = head;
			
			while(temp.next != null)
			{
				System.out.print(temp.data+" ");
				temp = temp.next;
			}
			
			System.out.print(temp.data+"\n");
			
			/*		
			System.out.println("BACK-WARD");
			while(temp !=null)
			{
				System.out.print(temp.data+" ");
				temp = temp.prev;
			}
			*/
		}
		
		//position starting from the 1,2,3...n
		Node deleteAtPosition(Node head,int position)
		{
			if(head == null)
				return head;
			
			Node temp = head;
			position--;
			
			while(position!=0 && temp != null)
			{	
				temp = temp.next;
				position--;
			}
			
			if(position != 0)
				System.out.println("Position > Length");
			else
			{
				temp.prev.next = temp.next;
				temp.next.prev = temp.prev;
			
				//delinking the node(removing)
				temp.next = null;
				temp.prev = null;
				System.out.print("Element Deleted:"+temp.data);	
			}
			
			return head;
		}
		
		//reversing linked list using loops
		private Node reverseListLoop(Node head)
		{
			if(head.next == null)
				return head;
			
			Node curr = head;
			Node prev = null;
			Node next = null;
			
			while(curr.next != null)
			{
				next = curr.next;
				curr.next = prev;
				prev = curr;
				
				curr = next;
			}
			
			return curr;
		}
	}
}
