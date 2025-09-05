import java.util.Scanner;

/**
 * @purpose:test the Fibonacci class
 * 
 * @author Kauan Lima
 * @version 4/12/2024
 */
public class FibonacciTester
{
	public static void main(String[] args)
	{
		//repeat until negative value is entered
		while (true)
		{
			//prompt for value
			Scanner in = new Scanner(System.in);
			System.out.print("Enter an integer value for n (enter negative value to quit): ");
			int n = in.nextInt();
			
			//print number at value n
			int fValue = Fibonacci.FibonacciSelect(n);
			System.out.println(fValue);
			System.out.println();  
		} 
	}
}
