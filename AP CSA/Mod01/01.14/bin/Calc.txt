
public class Calc
{
	public static void main(String[] args)
	{
		
		int value = 15;
		int divisor = 2;
		//calculation and output statements
		System.out.println("The original value is " + value);
		System.out.println("When " + value + " is divided by " + divisor + ", the whole number result is " + (value/divisor));
		System.out.println("The remainder of " + value + " divided by " + divisor + " is " + (value % divisor));
		System.out.print("When " + value + " is divided by " + divisor + ", the decimal result is " + ((double)value / divisor));
	}
}
