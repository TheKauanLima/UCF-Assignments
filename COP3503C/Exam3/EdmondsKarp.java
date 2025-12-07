//Dr. Steinberg
//COP3503 Computer Science 2
//EdmondsKarp.java

import java.util.*;


class Graph 
{
	final int V;
	final int[][] capacity;
	int[][] flow;

	public Graph(int V) 
	{
		this.V = V;
		capacity = new int[V][V];
		flow = new int[V][V];
	}

	public void addEdge(int u, int v, int c) 
	{
		capacity[u][v] = c;
	}


	public boolean bfs(int s, int t, int[] parent) 
	{
		Arrays.fill(parent, -1);
		parent[s] = -2;
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[]{s, Integer.MAX_VALUE});

		while(!queue.isEmpty()) 
		{
			int[] pair = queue.poll();
			int u = pair[0];
			int flowToU = pair[1];

			for(int v = 0; v < V; v++) 
			{
				int residualCapacity = capacity[u][v] - flow[u][v];
				if(residualCapacity > 0 && parent[v] == -1) 
				{
					parent[v] = u;
					int newFlow = Math.min(flowToU, residualCapacity);
					if (v == t)
						return true; 
					queue.add(new int[]{v, newFlow});
				}
			}
		}
		return false;
	}

	public int maxFlow(int s, int t) 
	{
		int maxFlow = 0;
		int[] parent = new int[V];

		while(bfs(s, t, parent)) 
		{
			int pathFlow = Integer.MAX_VALUE;
			for(int v = t; v != s; v = parent[v]) 
			{
				int u = parent[v];
				pathFlow = Math.min(pathFlow, capacity[u][v] - flow[u][v]);
			}

			//Update flow and reverse edges
			for(int v = t; v != s; v = parent[v]) 
			{
				int u = parent[v];
				flow[u][v] += pathFlow;
				flow[v][u] -= pathFlow; //reverse edge
			}

			maxFlow += pathFlow;
			
			displayFlows();
			
		}

		return maxFlow;
	}
	
	
	public void displayFlows() 
	{
		System.out.println("\nEdges with flow and capacity:");
		for(int u = 0; u < V; u++) 
		{
			for(int v = 0; v < V; v++) 
			{
				if (capacity[u][v] > 0) 
				{
					System.out.printf("Edge %d -> %d | Flow: %d / Capacity: %d%n", u, v, flow[u][v], capacity[u][v]);
				}
			}
		}
	}
	
}

public class EdmondsKarp 
{
    public static void main(String[] args) 
	{
        Graph g = new Graph(6);
        g.addEdge(0, 1, 3);
		g.addEdge(0, 3, 8);
		g.addEdge(1, 2, 1);
		g.addEdge(1, 4, 4);
		g.addEdge(2, 5, 7);
		g.addEdge(3, 2, 3);
		g.addEdge(3, 4, 7);
		g.addEdge(4, 5, 5);


        int source = 0, sink = 5;
        System.out.println("The maximum possible flow is " + g.maxFlow(source, sink));
		g.displayFlows();
    }
}
