/* Dr. Steinberg
   COP3503 Computer Science 2
   N-Queens
   NQueen.java
   This version will only print one solution.
   After compiling, run as java NQueen [SOME INTEGER]
*/

import java.util.*;

public class NQueen
{
	private int n;
	private int board[][];
	private boolean [] rowused;
	private boolean [] ddiagused;
	private boolean [] udiagused;
	
	
	public NQueen(int n)
	{
		this.n = n;
		this.rowused = new boolean [n];
		this.ddiagused = new boolean [2 * n];
		this.udiagused = new boolean [2 * n];
		this.board = new int [n][n];
	}
	
	public boolean solveNQueen()
	{
		// java did all the work for us already
		return solveNQueenR(0);
	}
	
	public boolean solveNQueenR(int k)
	{
		for (int x = 0; x < n; x++)
		{
			if(positionOk(x, k))
			{
				rowused[x] = true;
				udiagused[k + x] = true;
				ddiagused[n - k + x] = true;
				board[x][k] = 1; //place queen

				// check if our answer is complete
				if (k == n - 1) 
					return true; // we are done
				else // go to next column
				{
					if (solveNQueenR(k + 1))
						return true; // we are done
					else
					{
						// backtrack
						rowused[x] = false;
						udiagused[k + x] = false;
						ddiagused[n - k + x] = false;
						board[x][k] = 0; // remove queen
					}
				}
			}
		}
		return false;
	}
	
	public boolean positionOk(int x, int k)
	{
		return !(rowused[x] || ddiagused[n - k + x] || udiagused[k + x]); //check to see if another queen already occupies a certain spot
	}
	
	public String toString()
	{
		StringBuilder str = new StringBuilder("Board Size: ");
		str.append(n + " X " + n + "\n");
		str.append("Board Visualization\n");
		for(int row = 0; row < n; ++row)
		{
			for(int column = 0; column < n; ++column) 
				str.append(board[row][column] + " ");
			
			str.append("\n");
		}
		return str.toString();
	}
	
	public static void main(String [] args)
	{
		
		if(args.length < 1) 
		{
            System.out.println("Please provide an integer as a command-line argument. Example: java NQueen 4");
            return;
        }
		
		
		int value = 0;
		
		try 
		{
            value = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) 
		{
            System.out.println("The argument provided is not a valid integer.");
        }
		
		
		
		NQueen obj1 = new NQueen(value); 
		
		obj1.solveNQueen();
		
		System.out.println(obj1.toString());
	}
}