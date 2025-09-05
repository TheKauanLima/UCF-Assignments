/**
 * Without modifying any of the method signatures, correct add method calls to the already created methods in the main() below 
 *
 * Display by printing what the different functions do by calling them from main().
 *
 * APCS Team 2020 (Edited by: Kauan Lima)
 * @author Kauan Lima
 * @version 6/28/2023
 */ 
 public class MakingMethodCalls

{
    public static void addTheseTwo()
    {
        System.out.println("Ten plus five equals " + (10 + 5));
    }   
    
    public static void multiplyTheseTwo(int a, int b)
    {
        System.out.println("Ten times five equals " + (a * b));
    }  
    
    public static int divideTheseTwo(int a, int b)
    {
        return (a / b);
    }    
    
    public static void main(String[] args)
    {
        int x = 10;
        int y = 5;
        
        /**
         * Insert code here that calls one of the above methods that results in.
         * computer printing out "Ten plus five equals 15"
         */
        addTheseTwo();


        /**
         * Insert code here that calls one of the above methods that results in.
         * computer printing out "Ten times five equals 50"
         */
        multiplyTheseTwo(x, y);

        
        
        /**
         * Insert code here that calls one of the above methods that results in.
         * computer printing out "Ten divided by five equals 2"
         */
        int division = divideTheseTwo(x, y);
        System.out.print("Ten divided by five equals " + division);

    }//end of main method
}//end of class
