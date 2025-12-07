public class Q1
{
    public static boolean loops(int adjmatrix[][], int numvertices)
    {
        for (int u = 0; u < numvertices; u++)
        {
            for (int v = 0; v < numvertices; v++)
            {
                if (u != v)
                {
                    for (int w = 0; w < numvertices; w++)
                    {
                        if (w != v && w != u)
                        {
                        if(adjmatrix[u][v] == 1 && adjmatrix[v][w] == 1 && adjmatrix[w][u] == 1)
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    public static void bfs(int[][] link, int start, boolean[] visited)
    {
        //
    }

    public static boolean isNetworkConnected(int[][] link, int numComputers)
    {
        boolean[] visited = new boolean[numComputers];

        bfs(link, 0, visited);

        for (boolean v : visited)
            if (!v)
                return false;

        int[][] transposed = new int[numComputers][numComputers];

        for (int i = 0; i < numComputers; i++)
            for (int j = 0; j < numComputers; j++)
                transposed[j][i] = link[i][j];

        visited = new boolean[numComputers];

        bfs(link, 0, visited);

        for (boolean v : visited)
            if (!v)
                return false;

        return true;
    }
}