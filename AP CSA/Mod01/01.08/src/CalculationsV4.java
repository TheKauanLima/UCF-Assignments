
/**
 * The Calculations class performs addition, subtraction,
 * multiplication, division, and modulus operations on integers and
 * decimals.
 *  
 * @ author APCS Team
 * @ version 2020
 */
public class CalculationsV4
{
    public static void main(String[ ] args)
    {
    	// Declare integer variables
    	// Addition
    	int iAddNum1 = 25;
    	int iAddNum2 = 9;
    	// Extra addition variables
    	int iAddNum3 = 53;
    	int iAddNum4 = 28;
    	
    	// Subtraction
    	int iSubNum1 = 11;
    	int iSubNum2 = 9;
    	int iSubNum3 = 25;
    	// Extra Subtraction variables
    	int iSubNum4 = 51;
    	int iSubNum5 = 34;
    	int iSubNum6 = 10;
    	
    	// Multiplication
    	int iMulNum1 = 25;
    	int iMulNum2 = 9;
    	// Extra Multiplication variables
    	int iMulNum3 = 17;
    	int iMulNum4 = 23;
    	
    	// Division
    	int iDivNum1 = 9;
    	int iDivNum2 = 25;
    	
    	// Modulus
    	int iModNum1 = 11;
    	int iModNum2 = 9;
    	
        // Addition
        System.out.println("Addition");
        System.out.println(iAddNum1 + " + " + iAddNum2 + " = "  + (iAddNum1 + iAddNum2));
        System.out.println("43.21 + 3.14 = " + (43.21 + 3.14));
        System.out.println();
        
        // Subtraction
        System.out.println("Subtraction");
        System.out.println(iSubNum1 + " - " + iSubNum2 + " - " + iSubNum3 + " = " + (iSubNum1 - iSubNum2 - iSubNum3));
        System.out.println("3.14 - 10.0 = " + (3.14 - 10.0));
        System.out.println();
        
        // Multiplication
        System.out.println("Multiplication");
        System.out.println(iMulNum1 + " * " + iMulNum2 + " = " + (iMulNum1 * iMulNum2)); 
        System.out.println("3.14 * 10.0 * 10.0 = " + (3.14 * 10.0 * 10.0));
        System.out.println();
        
        // Division
        System.out.println("Division");
        System.out.println(iDivNum1 + " / " + iDivNum2 + " = " + (iDivNum1 / iDivNum2));
        System.out.println("43.21 / 10.0 = " + (43.21 / 10.0 ));
        System.out.println();
         
        // Modulus operator
        System.out.println("Modulus");
        System.out.println(iModNum1 + " % " + iModNum2 + " = " + (iModNum1 % iModNum2));
        System.out.println("10.0 % 3.14 = " + (10.0 % 3.14 ));
        System.out.println();
        
        // 1.08 Additional int Equations
        // Extra addition
        System.out.println("Extra Addition");
        System.out.println(iAddNum3 + " + " + iAddNum4 + " = "  + (iAddNum3 + iAddNum4));
        System.out.println();
        
        // Extra subtraction
        System.out.println("Extra Subtraction");
        System.out.println(iSubNum4 + " - " + iSubNum5 + " - " + iSubNum6 + " = " + (iSubNum4 - iSubNum5 - iSubNum6));
        System.out.println();
        
        //Extra multiplication
        System.out.println("Extra Multiplication");
        System.out.println(iMulNum3 + " * " + iMulNum4 + " = " + (iMulNum3 * iMulNum4));
        System.out.println();
        
        // 1.09 Additional double Equations
               
    } // end of main method
} // end of class
