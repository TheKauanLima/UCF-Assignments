package Exam2.DP;

public class EditDistance {

    public static int min(int x, int y, int z)
    {
        if (x <= y && x <= z)
            return x;
        if (y <= x && y <= z)
            return y;
        else
            return z;
    }

    public static int editDistance(String X, String Y, int m, int n)
    {
        if (m == 0)
            return n;
        if (n == 0)
            return m;
        
        if (X.charAt(m-1) == Y.charAt(n-1))
            return editDistance(X, Y, m-1, n-1);
        return 1 + min(editDistance(X, Y, m-1, n), editDistance(X, Y, m-1, n-1), editDistance(X, Y, m, n-1));
    }

    public static int editDistanceMemo(String X, String Y, int m, int n, int[][] memo)
    {
        if (m == 0)
            return n;
        if (n == 0)
            return m;
        if (memo[m][n] != 0)
            return memo[m][n];
        
        if (X.charAt(m-1) == Y.charAt(n-1))
            memo[m][n] = editDistanceMemo(X, Y, m-1, n-1, memo);
        else
            memo[m][n] = 1 + min(editDistance(X, Y, m-1, n), editDistance(X, Y, m-1, n-1), editDistance(X, Y, m, n-1));
        return memo[m][n];
    }

    public static int editDistanceTab(String X, String Y, int m, int n)
    {
        int[][] c = new int[m+1][n+1];

        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if (i == 0)
                    c[i][j] = j;
                else if (j == 0)
                    c[i][j] = i;
                else if (X.charAt(i - 1) == Y.charAt(j - 1))
                    c[i][j] = c[i-1][j-1];
                else
                    c[i][j] = 1 + min(c[i][j-1], c[i-1][j-1], c[i-1][j]);
            }
        }
        return c[m][n];
    }

    public static void main(String[] args)
    {
        String s1 = "program";
        String s2 = "propgress";
        int m = s1.length();
        int n = s1.length();

        int[][] memo = new int[m+1][n+1];
        //for (int i = )

        System.out.println("rec: " + editDistance(s1, s2, m, n));
        System.out.println("memo: " + editDistanceMemo(s1, s2, m, n, memo));
        System.out.println("tab: " + editDistanceTab(s1, s2, m, n));
    }
}
