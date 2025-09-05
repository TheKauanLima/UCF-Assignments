
/**
 * Purpose: CalculationsV6 takes several integer and double values
 * and then performs operations based on the operands assigned,
 * the operands can be either: addition, subtraction, multiplication,
 * division, or modulus.
 *  
 * @author Kauan Lima
 * @version June 10, 2023
 */
public class CalculationsV6
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
    	
    	//Declare double variables
    	// Addition
    	double dAddNum1 = 43.21;
    	double dAddNum2 = 3.14;
    	
    	// Subtraction
    	double dSubNum1 = 3.14;
    	double dSubNum2 = 10.0;
    	
    	// Multiplication
    	double dMulNum1 = 3.14;
    	double dMulNum2 = 10.0;
    	double dMulNum3 = 10.0;
    	// Extra multiplication
    	double dMulNum4 = 2.178;
    	double dMulNum5 = 12.6;
    	double dMulNum6 = 5.13;
    	
    	// Division
    	double dDivNum1 = 43.21;
    	double dDivNum2 = 10.0;
    	// Extra division
    	double dDivNum3 = 65.1;
    	double dDivNum4 = 21.6;
    	
    	// Modulus
    	double dModNum1 = 3.14;
    	double dModNum2 = 10.0;
    	// Extra modulus
    	double dModNum3 = 2.178;
    	double dModNum4 = 34.54;
    	
    	// Operations
        // Addition
        System.out.println("Addition");
        System.out.println(iAddNum1 + " + " + iAddNum2 + " = "  + (iAddNum1 + iAddNum2));
        System.out.println(dAddNum1 + " + " + dAddNum2 + " = " + (dAddNum1 + dAddNum2));
        System.out.println();
        
        // Subtraction
        System.out.println("Subtraction");
        System.out.println(iSubNum1 + " - " + iSubNum2 + " - " + iSubNum3 + " = " + (iSubNum1 - iSubNum2 - iSubNum3));
        System.out.println(dSubNum1 + " - " + dSubNum2 + " = " + (dSubNum1 - dSubNum2));
        System.out.println();
        
        // Multiplication
        System.out.println("Multiplication");
        System.out.println(iMulNum1 + " * " + iMulNum2 + " = " + (iMulNum1 * iMulNum2)); 
        System.out.println(dMulNum1 + " * " + dMulNum2 + " * " + dMulNum3 + " = " + (dMulNum1 * dMulNum2 * dMulNum3));
        System.out.println();
        
        // Division
        System.out.println("Division");
        System.out.println(iDivNum1 + " / " + iDivNum2 + " = " + (iDivNum1 / iDivNum2));
        System.out.println(dDivNum1 + " / " + dDivNum2 + " = " + (dDivNum1 / dDivNum2));
        System.out.println();
         
        // Modulus operator
        System.out.println("Modulus");
        System.out.println(iModNum1 + " % " + iModNum2 + " = " + (iModNum1 % iModNum2));
        System.out.println(dModNum1 + " % " + dModNum2 + " = " + (dModNum1 % dModNum2));
        System.out.println();
        
        // 1.08 Additional int Equations
        // Operations
        // Extra addition
        System.out.println("Extra Integer Addition");
        System.out.println(iAddNum3 + " + " + iAddNum4 + " = "  + (iAddNum3 + iAddNum4));
        System.out.println();
        
        // Extra subtraction
        System.out.println("Extra Integer Subtraction");
        System.out.println(iSubNum4 + " - " + iSubNum5 + " - " + iSubNum6 + " = " + (iSubNum4 - iSubNum5 - iSubNum6));
        System.out.println();
        
        //Extra multiplication
        System.out.println("Extra Integer Multiplication");
        System.out.println(iMulNum3 + " * " + iMulNum4 + " = " + (iMulNum3 * iMulNum4));
        System.out.println();
        
        // 1.09 Additional double Equations
        // Operations
        // Extra multiplication
        System.out.println("Extra Double Multiplication");
        System.out.println(dMulNum4 + " * " + dMulNum5 + " * " + dMulNum6 + " = " + (dMulNum4 * dMulNum5 * dMulNum6));
        System.out.println();
        
        //Extra division
        System.out.println("Extra Double Division");
        System.out.println(dDivNum3 + " / " + dDivNum4 + " = " + (dDivNum3 / dDivNum4));
        System.out.println();
        
        //Extra modulus
        System.out.println("Extra Double Modulus");
        System.out.println(dModNum3 + " % " + dModNum4 + " = " + (dModNum3 % dModNum4));
        System.out.println();
        
    } // end of main method
} // end of class
