import java.util.ArrayList;

public class ComboBT
{
    public static void printComboR(ArrayList<Integer> arr, ArrayList<Integer> out, int k, int i)
    {
        if (i == k)
        {
            System.out.println(out.toString());
            return;
        }

        for (int j = 0; j < k; j++)
        {
            out.add(arr.get(j));
            printComboR(arr, out, k, i+1);
            out.remove(out.size() - 1);
        }
    }

    public static void main(String[] args)
    {
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> out = new ArrayList<>();

        arr.add(1);
        arr.add(2);
        arr.add(1);
        printComboR(arr, out, 2, 0);
    }
}
