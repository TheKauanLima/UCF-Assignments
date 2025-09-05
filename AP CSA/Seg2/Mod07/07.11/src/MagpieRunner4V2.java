
/**
 * A simple class to run the Magpie class.
 *
 * Code adapted from work by Laurie White for the College Board.
 *
 * @author Kauan Lima
 * @version 3/3/2024
 */

import java.util.Scanner;

public class MagpieRunner4V2
{

    /**
     * Create a Magpie, give it user input, and print its replies.
     */
    public static void main(String[] args)
    {
        Magpie4V2 maggie = new Magpie4V2();

        System.out.println (maggie.getGreeting());
        Scanner in = new Scanner (System.in);
        String statement = in.nextLine();

        while (!statement.equals("Bye"))
        {
            System.out.println (maggie.getResponse(statement));
            statement = in.nextLine();
        }
    }

}
