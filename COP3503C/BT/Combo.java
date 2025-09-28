package COP3503C.BT;


import java.util.ArrayList;

public class Combo {
    public static void printComboR(ArrayList<Integer> al, ArrayList<Integer> out, int k, int i)
    {
        if (i >= k)
        {
            out.toString();
        }

        out.add(al.get(i));
        printComboR(al, out, k, i+1);
        out.remove(al.get(i));
    }
    public static void main(String[] args)
    {
        ArrayList<Integer> al = new ArrayList<>();
        ArrayList<Integer> out = new ArrayList<>();
        al.add(1);
        al.add(2);
        al.add(1);
        printComboR(al, out, 2, 0);
    }
}
