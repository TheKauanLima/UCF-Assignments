/**
 * @purpose: Use a 2d array to print a table of values for different starting conditions of a catapult.
 * 
 * @author Kauan Lima
 * @version 3/10/2024
 */
public class CatapultTester
{
	public static void main(String[] args)
	{
		//create new catapult object
		Catapult cata = new Catapult();
		
		//initialize necessary arrays
		int[] speedArray = { 20, 25, 30, 35, 40 };
		int[] angleArray = { 25, 30, 35, 40, 45, 50 };
		double[][] twoDimArray = new double[5][6];
		
		//calculate the value for each position of twoDimArray and insert
		for(int rows = 0; rows < twoDimArray.length; rows++)
			for(int columns = 0; columns < twoDimArray[rows].length; columns++)
				twoDimArray[rows][columns] = cata.calcDistance(speedArray[rows], angleArray[columns]);
		
		//print final results
		printResults(twoDimArray, angleArray, speedArray);
	}
	
	public static void printResults(double[][] array, int[] angleArray, int[] speedArray)
	{
		//convert m/s to km/hr
		for(int i = 0; i < speedArray.length; i++)
			speedArray[i] *= 3.6;
		
		//print header
		System.out.println("                           Projectile Distance (meters)");
		System.out.print("KPH");
		
		//print all different degrees
		for(int i = 0; i < angleArray.length; i++)
            System.out.printf("%9d deg", angleArray[i]);
		System.out.println("\n=======================================================================================");
		
		//print the calculated values
		for(int row = 0; row < array.length; row ++)
        {
			//print all different speeds
            System.out.printf("%-5d", speedArray[row]);

            //twoDimArray table
            for(int col = 0; col < array[row].length; col ++)
                System.out.printf("     %-8.2f", array[row][col]);
            System.out.println();
        }
	}
}