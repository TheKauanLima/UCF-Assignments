
/**
 * The purpose of this program is to generate a table of random
 * integers using the Random class nextInt() method.
 *
 * @author Charles Babbage
 * @version 06/05/17
 */
import java.util.Random;
public class RandomNumbers
{
    public static void main(String[] args)
    {
    	
    	int count = 1;
    	for(int outer = 0; outer < 4; outer++)
    	{
    	   for(int inner = 1; inner < 3; inner++)
    	   {
    	     count++;
    	   }
    	   System.out.println(count);
    	}
    	
    	int x = 1;
    	int y = 0;
    	while (x < 10)
    	{
    	   y = 5;
    	   while (y > x)
    	   {
    	       y--;
    	   }
    	   x += y;
    	}
    	System.out.println(x);
    	
    	for(int outer = 0; outer < 4; outer++)
    	{
    	   for(int inner = 0; inner < 5; inner++)
    	   {
    	      System.out.print("∗");
    	   }
    	   System.out.println();
    	}
    	
        int randNum = 0;
        Random randNumList = new Random();

        System.out.println("        Table of Random Numbers  ");
        for(int row = 0; row < 5; row++)
        {
            for(int col = 0; col < 10; col++)
            {
                randNum = randNumList.nextInt(100);   //random numbers from 0 to 99
                System.out.print(randNum + "\t ");
            }//end column loop
            System.out.println();
        }//end row loop
    }//end main
}//end class