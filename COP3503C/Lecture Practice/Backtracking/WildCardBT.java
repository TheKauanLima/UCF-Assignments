public class WildCardBT {
    public static void printAllCombinations(char[] binary, int idx)
    {
        if (idx == binary.length)
        {
            System.out.println(binary);
            return;
        }
        else if (binary[idx] == '?')
        {
            for (char ch = '0'; ch <= '1'; ch++)
            {
                binary[idx] = ch;
                printAllCombinations(binary, idx + 1);
                binary[idx] = '?';
            }
        }
        else
        {
            printAllCombinations(binary, idx + 1);
        }
        // for (int j = idx; j < binary.length; j++)
        // {
        //     if (binary[j] == '?')
        //     {
        //         binary[j] = '0';
        //         printAllCombinations(binary, j+1);
        //         binary[j] = '1';
        //         printAllCombinations(binary, j+1);
        //         binary[j] = '?';
        //     }
        // }
    }

    public static void main(String[] args)
    {
        char[] arr = { '1', '?', '1', '1', '?', '0', '0', '?', '1', '?' };
        printAllCombinations(arr, 0);
    }
}
