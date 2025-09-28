package COP3503C.LabPractice;

import java.util.Scanner;

public class DNC {
    public static int findMax(int[] arr, int left, int right)
    {
        if(left == right)
            return arr[left];

        int mid = left + (right - left) / 2;
        int maxLeft = findMax(arr, left, mid);
        int maxRight = findMax(arr, mid + 1, right);
        return Math.max(maxLeft, maxRight);
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scan.nextInt();
        
        if(n < 1)
            return;
        
        int [] arr = new int[n];
        
        System.out.println("Enter the elements: ");
        
        for(int i = 0; i < n; ++i)
            arr[i] = scan.nextInt();
        
        int maxElement = findMax(arr, 0, n - 1);
        
        System.out.println("Maximum element: " + maxElement);
        
        scan.close();
    }
}
