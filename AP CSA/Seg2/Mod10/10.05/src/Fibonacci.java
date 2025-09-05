/**
 * @purpose:repeat the fibonacci sequence
 * 
 * @author Kauan Lima
 * @version 4/12/2024
 */
public class Fibonacci
{
	public static int FibonacciSelect(int n)
	{
		int fValue = 0;
		if (n > 1)
		{
			fValue = FibonacciSelect(n-1) + FibonacciSelect(n-2);
			return fValue;
		}
		else if (n == 1)
			return 1;
		else if (n == 0)
			return 0;
		else
			System.exit(0);
		return fValue;
	}
}
