/**
 * This is a class that tests the Card class.
 *
 *  @author Kauan Lima
 *  @version 4/18/24
 */

public class CardTester
{
   /**
    * The main method in this class checks the Card operations for consistency.
    * @param args is not used.
    */
   public static void main(String[] args) {

      /* *** TO BE IMPLEMENTED IN ACTIVITY 1 *** */

      // Establish new cards
      Card aceHearts = new Card("ace", "hearts", 1);
      Card sixSpades = new Card("6", "spades", 6);
      Card kingClubs = new Card("king", "clubs", 13);

      // Test card 1 and methods
      System.out.println("**** Tests Card 1: ace of hearts ****");
      System.out.println("  rank: " + aceHearts.rank());
      System.out.println("  suit: " + aceHearts.suit());
      System.out.println("  pointValue: " + aceHearts.pointValue());
      System.out.println("  toString: " + aceHearts.toString());
      System.out.println();

      // Test card 2
      System.out.println("**** Tests Card 2: 6 of spades ****");
      System.out.println("  rank: " + sixSpades.rank());
      System.out.println("  suit: " + sixSpades.suit());
      System.out.println("  pointValue: " + sixSpades.pointValue());
      System.out.println("  toString: " + sixSpades.toString());
      System.out.println();
      
      // Test card 3
      System.out.println("**** Tests Card 3: king of clubs ****");
      System.out.println("  rank: " + kingClubs.rank());
      System.out.println("  suit: " + kingClubs.suit());
      System.out.println("  pointValue: " + kingClubs.pointValue());
      System.out.println("  toString: " + kingClubs.toString());
      System.out.println();
      
      // Test matches() method
      System.out.println("**** matches tests ****");
      System.out.println("  card 1 & card 3: " + aceHearts.matches(kingClubs));
      System.out.println("  card 2 & card 1: " + sixSpades.matches(aceHearts));
      System.out.println("  card 3 & card 3: " + kingClubs.matches(kingClubs));
   }
}
