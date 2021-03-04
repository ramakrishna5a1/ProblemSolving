/*
	This class is an implementation of MIN Heap
*/


public class HeapDemo
{
	final int MAX = 10;
	private int[] heap= new int[MAX];
	private int index=-1,temp;
	
	public static void main(String args[]){
		HeapDemo hp=new HeapDemo();
		int[] ar = new int[]{1};	
		
		for(int i=0;i<ar.length;i++)
			hp.insert(ar[i]);
		
		hp.heapSort();
		//hp.deleteMin();
		
		hp.display();
	}
	private void heapSort(){
		int temp = index;
		
		while(index>=0)
		{
			int min = heap[0];
			heap[0] = heap[index];
			heap[index] = min;
			index--;
			
			heapifyDown(0);
		}
		
		index = temp;
	}
	
	private void display(){
		for(int i=0;i<=index;i++)
			System.out.print(heap[i]+" ");
		System.out.println();
	}
	
	public int getMin(){
		if(index == -1)
			return -1;
		
		return heap[0];
	}
	
	public int deleteMin(){
		if(index == -1)
			return -1;
	
		int min = heap[0];
		heap[0] = heap[index--];		
		heapifyDown(0);
		return min;		
	}
	
	public boolean insert(int ele)
	{
		if((index+1) == MAX)
			return false;
		
		index++;
		heap[index] = ele;
		heapifyUp(index);
		
		return true;
	}
	
	private void heapifyDown(int i){
		int l = getLeftChild(i);
		int r = getRightChild(i);
		int small = i;
		
		if(l <= index && heap[small] > heap[l])
			small = l;
		if(r <= index && heap[small] > heap[r])
			small = r;
		
		if(small != i){
			//swap both and call heapifyDown
			int temp = heap[i];
			heap[i] = heap[small];
			heap[small] = temp;
			
			heapifyDown(small);	
		}
	}	
	
	private void heapifyUp(int index){
		if(index == 0)
			return;
		int parent = getParent(index);
		
		//comparing child and parent
		if(parent >= 0 && heap[index]<heap[parent])
		{
			temp = 	heap[index];
			heap[index] = heap[parent];
			heap[parent] = temp;
			
			heapifyUp(parent);
		}
	}	
	
	private int getParent(int i){
		return (i-1)/2;
	}
	
	private int getLeftChild(int i){
		return 2*i+1;
	}
	
	private int getRightChild(int i){
		return 2*i+2;
	}	
}

