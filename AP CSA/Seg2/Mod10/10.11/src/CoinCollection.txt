/**
 * @purpose: Create a collection of coins and their rarities.
 * 
 * @author Kauan Lima
 * @version 4/22/2024
 */

import java.util.ArrayList;

public class CoinCollection
{
	private ArrayList<Coin> coins; //collection of coins
	
	//precondition: parallel arrays of all the same length
	//write the constructor of CoinCollection for part A
	public CoinCollection(int[] years, double[] values, String[] countries)
	{
		//to be completed in part A
		coins = new ArrayList<Coin>();
		
		for (int i = 0; i < years.length; i++)
			coins.add(new Coin(years[i], values[i], countries[i]));
	}
	
	//there may be other constructors and methods not shown
	public boolean isRare(int year)
	{
		//to be completed in part B
		for (int i = 0; i < coins.size(); i++)
			if (coins.get(i).getYear() >= year)
				return false;
		return true;
	}
}