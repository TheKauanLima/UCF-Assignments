import java.util.Scanner;

/**
 * @purpose: Test the CalcPrimes class
 * 
 * @author Kauan Lima
 * @version 3/31/2024
 */
public class PrimeTester 
{
	public static void main(String[] args)
	{
		// create scanner object
		Scanner in = new Scanner(System.in);
		
		// prompt for lower and upper limits
		System.out.print("Enter lower limit: ");
		int lower = in.nextInt();
		System.out.println();
		
		System.out.print("Enter upper limit: ");
		int upper = in.nextInt();
		System.out.println();
		
		in.close();
		
		// create object given limits
		CalcPrimes primes = new CalcPrimes(lower, upper);
		
		// calculate and display the information
		primes.detectPrimes();
		
	}
}
