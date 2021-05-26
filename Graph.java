import java.util.*;
/*
	Graph DataStructure:
	1,Adjacency List
	2,Adjacency Matrix
	
	Graph Traversals:
	1,DFS
	2,BFS
*/
class Graph{
	
	public static void main(String args[]){
		Graph graph = new Graph();
		Graph.AdjList adj = graph.new AdjList(4);
		
	}

	class AdjList
	{
		List<List<Integer>> adjList = null;
		int vCount;
		
		public AdjList(int vCount){
			this.vCount = vCount;
			adjList = new ArrayList<>(vCount);
			
			for(int i=0;i<vCount;i++)
				adjList.add(i,new LinkedList<>());
		}

		public void addEdge(int v,int e){
			adjList.get(v).add(e);
		}
	
		public void displayGraph(){
			int i=0;
			for(List<Integer> list : adjList){
				System.out.print((i++)+" ");
				for(int data : list)
					System.out.print("->"+data);				
				System.out.println();
			}
		}
		
		public void BFS()
		{ 
		//Using Queue for BFS
			boolean visited[] = new boolean[vCount];
			int exploreNode;
			List<Integer> res = new ArrayList<>(vCount);
			
			Queue<Integer> bfsQueue = new LinkedList<>();
			bfsQueue.add(2);
			visited[2] = true;
			
			while(!bfsQueue.isEmpty()){
				exploreNode = bfsQueue.poll();
				res.add(exploreNode);
				
				for(int data : adjList.get(exploreNode))
					if(!visited[data]){
						bfsQueue.add(data);
						visited[data] = true;
					}
			}
			
			System.out.println(res);
		}		

		public void DFS()
		{
			//using stack for DFS
			boolean visited[] = new boolean[vCount];
			int exploreNode;
			List<Integer> res = new ArrayList<>(vCount);

			Stack<Integer> st=new Stack<>();
			st.push(2);
			visited[2] = true;
		
			while(!st.isEmpty()){
				exploreNode = st.pop();
				res.add(exploreNode);			
				visited[exploreNode] = true;
				
				for(int data : adjList.get(exploreNode)){
					if(!visited[data]){
						st.push(data);
						visited[data] = true;
					}
				}
			}			
			System.out.println(res);
		}

	}
	
	class AdjMatrix
	{
		public void twodMatrixBFS(){
			int grid[][] = { { 1, 2, 3, 4 },
						 { 5, 6, 7, 8 },
						 { 9, 10, 11, 12 },
						 { 13, 14, 15, 16 } };		
			
			int ROW = grid.length;
			int COL = grid[0].length;
			boolean[][] visited = new boolean[ROW][COL];
			int adjX,adjY;
			ArrayList<Integer> res = new ArrayList<>();
			
			int[] dirX = {-1,0,1,0};
			int[] dirY = {0,1,0,-1};
			
			Queue<Integer[]> q = new LinkedList<>();
			
			q.add(new Integer[]{0,0});
			visited[0][0] = true;
			
			while(!q.isEmpty()){
				Integer[] curr = q.poll();
				int curX = curr[0];
				int curY = curr[1];
				
				res.add(grid[curX][curY]);
				
				for(int i=0;i<4;i++){
					adjX = curX + dirX[i];
					adjY = curY + dirY[i];
					
					//if it is reachable cell then mark it as visited and add to Queue
					if(isValidCell(adjX,adjY,visited)){
						q.add(new Integer[]{adjX,adjY});
						visited[adjX][adjY] = true;					
					}
				}
			}

			System.out.println(res);
		}
		
		public boolean isValidCell(int x,int y,boolean[][] visited){
			if(x<0 || y<0 || x>= visited.length || y>=visited[0].length || visited[x][y]) return false;
			return true;
		}	
	}
}
