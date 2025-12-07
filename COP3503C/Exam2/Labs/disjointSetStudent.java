// Disjoint Set (Union-Find) lab solution in Java
// Elements: 1..5
// Operations: Union(1,2), Union(3,4), Union(2,3)
// Queries: rep(1), rep(4), sameSet(1,5)

public class disjointSetStudent 
{

    static class DisjointSet 
	{
        private final int[] parent;
        private final int[] rank;

        // We’ll use 1-based indexing for simplicity (ignore index 0)
        DisjointSet(int n) 
		{
            parent = new int[n + 1];
            rank = new int[n + 1];
            makeSet(n);
        }

        // Make-Set for elements 1..n
        private void makeSet(int n) 
		{
            for (int i = 1; i <= n; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        // Find-Set with path compression
        int find(int x) 
		{
            if(parent[x] == x)
                return parent[x];
            int rep = find(parent[x]);
            parent[x] = rep;
            return rep;
        }

        // Union by rank
        void union(int x, int y) 
		{
            int repX = find(x);
            int repY = find(y);
            if (repX == repY) return;

            if (rank[repX] == rank[repY])
            {
                parent[repX] = repY;
                rank[repY]++;
            }
            else if (rank[repX] > rank[repY])
            {
                parent[repY] = repX;
            }
            else
            {
                parent[repX] = repY;
            }
        }

        boolean sameSet(int a, int b) 
		{
            int repA = find(a);
            int repB = find(b);
            return (repA == repB);
        }
    }

    public static void main(String[] args) 
	{
        DisjointSet ds = new DisjointSet(5); // elements 1..5

        // Perform the required unions
        ds.union(1, 2);
        ds.union(3, 4);
        ds.union(2, 3);

        // Queries
        int rep1 = ds.find(1);
        int rep4 = ds.find(4);
        boolean same = ds.sameSet(1, 5);

        // Output (example format)
        System.out.println("Representative of 1: " + rep1);
        System.out.println("Representative of 4: " + rep4);
        System.out.println("Are 1 and 5 in the same set? " + (same ? "Yes" : "No"));
    }
}
