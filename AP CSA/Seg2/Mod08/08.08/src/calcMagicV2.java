/**
 * @purpose: calculate all values for a 2d array given columns and rows
 * 			 find every odd value iterating from left to right and bottom to top
 * 
 * @author Kauan Lima
 * @version 3/29/2024
 */
import java.util.ArrayList;

public class calcMagicV2
{
	//part A
	public static int[][] calcMagicMath (int[] rowH, int[] colH)
	{
		//declare new variable with an extra column slot
		int[][] newArray = new int[rowH.length][colH.length + 1];
		
		//generate random value between 3 and 3 (inclusive) for the last column slot
		int newColumnValue = (int)(Math.random() * ((30-3) + 1) + 3);
		
		//check for repetition
		boolean rep = false;
		
		//iterate through each column
		for(int i = 0; i < colH.length; i++)
		{
			//check if i has equaled (colH.length - 1) before
			//if yes
			if (rep)
				//iterate through each row of the last column adding the additional values
				for(int j = 0; j < rowH.length; j++)
					newArray[j][i + 1] = newColumnValue*rowH[j];
			//if not
			else
				//iterate through each row of each column normally
				for(int j = 0; j < rowH.length; j++)
					newArray[j][i] = colH[i]*rowH[j];
			
			//if i == colH.length, do the loop once more with the rep value checked
			if (i == colH.length - 1 && !rep)
			{
				//force the loop to run once more
				i = colH.length - 2;
				
				//repetition value checked
				rep = true;
			}
		}
		
		//return 2D array
		return newArray;
	}
	
	//part B
	public static ArrayList<Integer> oddNumbers(int[][] twoD)
	{
		//declare new ArrayList
		ArrayList<Integer> oddNumbers = new ArrayList<>();
		
		//check starting from final row moving upward
		for(int i = twoD.length - 1; i >= 0; i--)
			//check starting from first column moving right
			for (int j = 0; j < twoD[0].length; j++)
				//if the value is not dividible by 2
				if (twoD[i][j] % 2 != 0)
					//add to the list
					oddNumbers.add(twoD[i][j]);
		
		return oddNumbers;
	}
	
	
	public static void main(String[] args)
	{
		//initialize the values to be multiplied for each column and row of the 2D array
		int[] colH = {3, 6, 9};
		int[] rowH = {2, 3, 6, 7};
		
		//declare new array with extra column
		int[][] newArray = new int[rowH.length][colH.length + 1];
		
		//run the array function
		newArray = calcMagicMath(rowH, colH);
		
		//display the array
		for(int i = 0; i < rowH.length; i++)
		{
			for(int j = 0; j <= colH.length; j++)
			{
				System.out.print(newArray[i][j]+ " ");
			}
			System.out.println();
		}
		
		//initialize new ArrayList with function
		ArrayList<Integer> oddNumbers = oddNumbers(newArray);
		
		//print ArrayList
		System.out.println(oddNumbers);
	}
	
}
