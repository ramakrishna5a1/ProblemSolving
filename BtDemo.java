//No package
import java.util.*;

public class BtDemo
{
	public static void main(String args[])
	{		
		BtDemo bt=new BtDemo();
		
		BtDemo.Node root = null;
		BtDemo.BinarySearchTree bst =bt.new BinarySearchTree();
		
		//inserting data into tree
		int[] data = {3,0,4,2,1};
		for(int i=0;i<data.length;i++)
			root = bst.insert(root,data[i]);
		
		//displaying the tree In-Order treversal
		bst.display(root);
		
		//max Depth of the tree
		System.out.println("\nDepth: "+bst.maxDepth(root));
		
		//All leaf Nodes
		ArrayList<Integer> list =new ArrayList<>();
		bst.getLeaveNodes(root,list);	
		System.out.println(list);
		
		//Level by level Nodes
		System.out.println();
		bst.levelsUsingStack(root);
		
		//Array to BST
		Arrays.sort(data);
		Node arrHead = bst.arrayToTree(data,0,data.length-1);
		System.out.println();
		bst.display(arrHead);
		
		//Top view of binary tree
		bst.topViewBinary(root,0,0);
		
		for(Map.Entry<Integer,Integer[]> singleNode : bst.top.entrySet()){
          		System.out.print(singleNode.getValue()[0]+" ");
		}
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
				System.out.print(root.data+" ");
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
		ArrayList<Integer> diagonal = null;
		
		public void diagonalTraversal(Node root,int path,HashMap<Integer,ArrayList<Integer>> map){
			if(root == null)
				return;
			
			diagonalTraversal(root.left,path+1,map);
		
			if(map.containsKey(root.data)){
				diagonal = map.get(root.data);		
			}else{
				diagonal = new ArrayList<>();	
			}	
			
			map.put(root.data,diagonal);			
			diagonalTraversal(root.left,path,map);
		}
		
		public ArrayList<Integer> getLeaveNodes(Node root,ArrayList<Integer> list){
			if(root == null) return list;
			
			if(root.left == null && root.right == null)
				list.add(root.data);
			
			getLeaveNodes(root.left,list);
			getLeaveNodes(root.right,list);
			
			return list;
		}
		
		void levelsUsingStack(Node root)
		{
			if(root == null)
				return;
				
			Queue<Node> q = new LinkedList<>();
			q.add(root);
			
			while(!q.isEmpty())
			{
				Node temp = q.poll();
				
				if(temp.left != null)
					q.add(temp.left);
				
				if(temp.right != null)
					q.add(temp.right);
				
				System.out.print(temp.data+" ");			
			}
		}
		
		/*
			Sorted array to binary search tree
		*/
		public Node arrayToTree(int[] arr,int left,int right)
		{
			if(left>right)
				return null;  
			
			int mid = (left+right)/2;
			Node new_node = new Node(arr[mid]);

			new_node.left = arrayToTree(arr,left,mid-1);
			new_node.right = arrayToTree(arr,mid+1,right);			
			
			return new_node;
		}
		
		Map<Integer,Integer[]> top=new TreeMap<>();
		Integer[] val_level=null;
		
		//left root right
		public void topViewBinary(Node root,int level,int hDist)
		{
			if(root == null)
				return;
			
			if(top.containsKey(hDist))
			{
				val_level = top.get(hDist);
				//current Level comparing with the exsiting level
				if(level<val_level[1])
				{
					//if it is less update val_level with new one
					val_level = {root.data,level};					
					val_level[0] = root.data;
					val_level[1] = level;
				}	
			}			
			else{
				val_level = new Integer[]{root.data,level};
			}
			top.put(hDist,val_level);	
            		topViewBinary(root.left,level+1,hDist-1);
            		topViewBinary(root.right,level+1,hDist+1);			
		}	
	}
}
