public class BtDemo
{
	public static void main(String args[])
	{		
		BtDemo bt=new BtDemo();
		
		BtDemo.Node root = null;
		BtDemo.BinarySearchTree bst =bt.new BinarySearchTree();
		
		//inserting data into tree
		int[] data = {1,2};
		
		for(int i=0;i<data.length;i++)
			root = bst.insert(root,data[i]);
		
		//displaying the tree In-Order treversal
		bst.display(root);
		
		//max Depth of the tree
		System.out.println("Depth: "+bst.maxDepth(root));
	}
	
	class Node
	{
		int data;
		Node left;
		Node right;
			
		public Node(int data){
			this.data = data;
			left=null;
			right=null;
		}
	}
	
	class BinarySearchTree
	{
		Node insert(Node root,int data)
		{
			Node newNode = new Node(data);

			if(root == null)
				return newNode;
			
			if(data <= root.data)
				root.left = insert(root.left,data);
			else if(data > root.data)
				root.right = insert(root.right,data);
			
			return root;
		}
		
		void display(Node root)
		{
			if(root != null){
				display(root.left);
				System.out.println(root.data);
				display(root.right);
			}
		}
		
		int maxDepth(Node root)
		{
			if(root == null)
				return 0;
	
			int left = maxDepth(root.left);
			int right = maxDepth(root.right);
	
			return (1+Math.max(left,right));
		}
	}
}
