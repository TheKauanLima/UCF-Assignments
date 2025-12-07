package Exam2.DP;
import java.util.*;
public class LCS {
    public static int lcs(String X, String Y, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;

        if(X.charAt(m-1) == Y.charAt(n-1))
            return 1 + lcs(X, Y, m-1, n-1);
        else
            return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
    }

    public static int lcsMemo(String X, String Y, int m, int n, int[][] memo)
    {
        if (m == 0 || n == 0)
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];
        
        if(X.charAt(m-1) == Y.charAt(n-1))
            memo[m][n] = 1 + lcsMemo(X, Y, m-1, n-1, memo);
        else
            memo[m][n] = max(lcsMemo(X, Y, m, n-1, memo), lcsMemo(X, Y, m-1, n, memo));
        
        return memo[m][n];
    }

    public static int lcsTab(String X, String Y, int m, int n)
    {
        int[][] c = new int[m+1][n+1];

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(X.charAt(i-1) == Y.charAt(j-1))
                    c[i][j] = 1 + c[i-1][j-1];
                else if(c[i-1][j] >= c[i][j-1])
                    c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }
            
        return c[m][n];
    }

    public static int max(int a, int b)
    {
        if (a>b)
            return a;
        else
            return b;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("X: ");
        String s1 = scanner.nextLine();
        System.out.println("Y: ");
        String s2 = scanner.nextLine();

        int m = s1.length();
        int n = s2.length();

        int[][] memo = new int[m+1][n+1];
        for (int i = 0; i < m + 1; i++)
            for (int j = 0; j < n + 1; j++)
                memo[i][j] = -1;
        
        System.out.println("rec: " + lcs(s1, s2, m, n));
        System.out.println("memo: " + lcsMemo(s1, s2, m, n, memo));
        System.out.println("tab: " + lcsTab(s1, s2, m, n));
    }
}
