/**
 * Purpose: Calculate the hypotenuse of two right triangles using the math class.
 * 
 * @author Kauan Lima
 * @version 6/28/23
 */
public class PyTheoremV3
{
	public static void main(String[] args)
	{
		// set the random number variables
		int minValue = 5;
		int maxValue = 23;
		double side1 = Math.random() * (maxValue-minValue) + minValue;
		double side2 = Math.random() * (maxValue-minValue) + minValue;
		
		// calculate the hypotenuse using random values
		double hypotenuse = Math.sqrt(Math.pow((int) side1, 2) + Math.pow((int) side2, 2));
		
		// print the values and result using sysout.print
		System.out.println("Triangle 1\t Side 1: " + (int) side1
				+ "\t Side 2: " + (int) side2 + "\t Hypotenuse: " + hypotenuse);
		
		// set the random values for triangle 2
		side1 = Math.random() * (maxValue-minValue) + minValue;
		side2 = Math.random() * (maxValue-minValue) + minValue;
		
		// calculate the hypotenuse for triangle 2
		hypotenuse = Math.sqrt(Math.pow((int) side1, 2) + Math.pow((int) side2, 2));
		
		// print the values and results once more
		System.out.print("Triangle 2\t Side 1: " + (int) side1
				+ "\t Side 2: " + (int) side2 + "\t Hypotenuse: " + hypotenuse);
	}
}