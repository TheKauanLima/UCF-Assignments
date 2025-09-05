/**
 * @purpose: Test the coin objects
 * 
 * @author Kauan Lima
 * @version 4/22/2024
 */

public class CoinTester
{

	public static void main(String[] args)
	{
		// initialize different arrays to test
		int[] yearsOne = { 1900, 1910, 1920 };
		double[] valuesOne = { 0.25, 0.10, 0.05 };
		String[] countriesOne = { "US", "US", "US" };
		
		int[] yearsTwo = { 1930, 1925, 1925 };
		double[] valuesTwo = { 1.00, 0.25, 0.05 };
		String[] countriesTwo = { "Mexico", "US", "Britain" };
		
		int[] yearsThree = { 1925, 1920, 1908 };
		double[] valuesThree = { 0.25, 0.50, 1.00 };
		String[] countriesThree = { "US", "US", "US" };
		
		// initialize all objects
		CoinCollection collectionOne = new CoinCollection(yearsOne, valuesOne, countriesOne);
		CoinCollection myCoins = new CoinCollection(yearsTwo, valuesTwo, countriesTwo);
		CoinCollection usCoins = new USCoinCollection(yearsThree, valuesThree, countriesThree);
		
		// test isRare
		System.out.println(myCoins.isRare(1930));
		System.out.println(usCoins.isRare(1930));
	}
}
