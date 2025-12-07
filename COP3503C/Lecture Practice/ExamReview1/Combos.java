import java.util.Arrays;

public class Combos {
    public static void findAllComboR(int[] arr, int x, int n)
    {
        if (x > n)
        {
            for (int j = 0; j < 2*n; j++)
            {
                if (arr[j] == -1)
                    return;
            }
            for (int j = 0; j < 2*n; j++)
            {
                System.out.print(arr[j]);
            }
            System.out.println();
            return;
        }

        for (int i = 0; i < 2*n; i++)
        {
            if (arr[i] != -1)
                continue;

            if (i > 0 && arr[i-1] == x && i+x < 2*n)
            {
                arr[i-1] = -1;
                arr[i+x] = -1;
            }
            
            if ((i+x+1 < 2*n) && arr[i+x+1] == -1)
            {
                arr[i] = x;
                arr[i+x+1] = x;
                findAllComboR(arr, x+1, n);
                arr[i] = -1;
                arr[i+x+1] = -1;
            }
        }
    }
    // public static void findAllComboR(int[] arr, int x, int n)
    // {
    //     if (x > n)
    //         return;

    //     int[] used = new int[2*n];
    //     int isXUsed = 0;
    //     for (int i = 0; i < 2*n; i++)
    //     {
    //         if(arr[i] > 0)
    //             used[i] = 1;
    //     }

    //     for (int i = 0; i < 2*n; i++)
    //     {
    //         if (used[i] == 1)
    //             continue;

    //         if (i > 0 && arr[i-1] == x && i+x < 2*n)
    //         {
    //             arr[i-1] = -1;
    //             used[i-1] = 0;
    //             arr[i+x] = -1;
    //             used[i+x] = 0;
    //             isXUsed = 0;
    //         }
            
    //         if ((i+x+1 < 2*n) && isXUsed == 0 && used[i+x+1] == 0)
    //         {
    //             arr[i] = x;
    //             used[i] = 1;
    //             arr[i+x+1] = x;
    //             used[i+x+1] = 1;
    //             isXUsed = 1;
    //         }
    //         else
    //             continue;
    //         findAllComboR(arr, x+1, n);
    //     }
    //     for (int j = 0; j < 2*n; j++)
    //     {
    //         if (arr[j] == -1 || used[j] == 0)
    //             return;
    //     }
    //     for (int j = 0; j < 2*n; j++)
    //     {
    //         System.out.print(arr[j]);
    //     }
    //     System.out.println();
    // }

    public static void findAllCombo(int n)
    {
        int[] arr = new int[2*n];
        Arrays.fill(arr, -1);
        findAllComboR(arr, 1, n);
    }

    public static void main(String[] args)
    {
        findAllCombo(3);
        System.out.println();
        findAllCombo(6);
    }
}
