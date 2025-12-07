import java.util.ArrayList;

public class PowerSetBT {
    public static void genPowerSet(ArrayList<Integer> nums, ArrayList<Integer> set, int i)
    {
        if(i < 0)
        {
            System.out.println(set);
        }
        else
        {
            set.add(nums.get(i));
            genPowerSet(nums, set, i - 1);
            set.remove(set.size() - 1);
            genPowerSet(nums, set, i - 1);
        }
    }

    // public static void genPowerSet(ArrayList<Integer> nums, ArrayList<Integer> output, int i)
    // {
    //     for (int j = i; j < nums.size(); j++)
    //     {
    //         System.out.println(output);
    //         output.add(nums.get(j));
    //         genPowerSet(nums, output, i+1);
    //         output.remove(output.size() - 1);
    //     }
    // }

    public static void main(String[] args)
    {
        ArrayList<Integer> nums = new ArrayList<>();
        ArrayList<Integer> output = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);
        genPowerSet(nums, output, nums.size() - 1);
    }
}
