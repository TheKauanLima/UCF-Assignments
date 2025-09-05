/**
 * @purpose: Display and count the number of prime numbers given a range
 * 
 * @author Kauan Lima
 * @version 3/31/2024
 */
public class CalcPrimes
{
	// private class variables
	private static int lower;
	private static int upper;
	
	// constructor
	public CalcPrimes(int lower, int upper)
	{
		this.lower = lower;
		this.upper = upper;
	}
	
	// method to detect and display prime values
	public static void detectPrimes()
	{
		// variables for confirming prime number and counting prime numbers
		boolean prime;
		int counter = 0;
		
		// print information
		System.out.println("The prime numbers between " + lower + " and " + upper + " are: ");
		
		for (int i = lower; i <= upper; i++)
		{
			prime = true;
			
			if (i <= 1)
			{
				prime = false;
				continue;
			}
			for (int j = 2; j*j <= i; j++)
				if (i % j == 0)
				{
					prime = false;
					continue;
				}
			
			if (prime)
			{
				System.out.print(i + "  ");
				counter++;
			}
		}
		
		System.out.println();
		System.out.println();
		System.out.println("There are a total of " + counter + " prime numbers.");
	}
}
