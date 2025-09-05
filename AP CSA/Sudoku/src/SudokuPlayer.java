/**
 * 
 * @author theka
 *
 */
public class SudokuPlayer
{
	public static void main(String[] args)
	{
		int[][] grid = createSudoku();
		printSudoku(grid);
	}
	
	public static void printSudoku(int[][] grid)
	{
		System.out.println("---------------------------------------");
		for (int i = 0; i < 9; i++)
		{
			System.out.print("| ");
			for (int j = 0; j < 9; j++)
			{
				if ((j+1) % 3 != 0 || (j+1) == 9)
					System.out.print(grid[i][j] + " | ");
				else if ((j+1) % 3 == 0)
					System.out.print(grid[i][j] + " || ");
			}
			System.out.println();
			if ((i+1) % 3 != 0 || (i+1) == 9)
				System.out.println("---------------------------------------");
			else if ((i+1) % 3 == 0)
				System.out.println("=======================================");
		}
	}
	
	public static int[][] createSudoku()
	{
		//boolean runVert = true;
		int[][] sudokuGrid = new int[9][9];
		
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int ranNum = (int)((Math.random()*9)+1);
				sudokuGrid[i][j] = ranNum;
				
				for (int k = j - 1; k >= 0; k--)
				{
					if (sudokuGrid[i][k] != ranNum)
					{
					}
					else {
						j--;
						break;
					}
					
					for (int m = i - 1; m >= 0; m--)
					{
						if (sudokuGrid[m][j] != ranNum)
							continue;
						else {
							ranNum = (int)((Math.random()*9)+1);
							sudokuGrid[m][j] = ranNum;
							m++;
							break;
						}
					}
				}
			}
		}
		return sudokuGrid;
	}
}