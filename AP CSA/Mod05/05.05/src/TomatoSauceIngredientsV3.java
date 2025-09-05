/**
 * Purpose: Construct a new class with two separate methods used to determine the taste of Tomato Sauce.
 * 
 * @author Kauan Lima
 * @version 9/17/2023
 */
public class TomatoSauceIngredientsV3
{
	//default constructor for the TomatoSauceIngredientsV3 class
	public TomatoSauceIngredientsV3()
	{
		
	}

	//method for determining the right amount of salt used
	public void salt(int pinches)
	{
		
		if (pinches < 3)
			System.out.println("Not enough salt!");
		else if (pinches < 6)
			System.out.println("Perfectly seasoned.");
		else
			System.out.println("Too salty!");
	}
	
	//method for determining the right amount of sofrito used.
	public void sofrito(double cups)
	{
		
		if (cups < 1)
			System.out.println("Too acidic!");
		else if (cups < 3)
			System.out.println("Perfectly sweet.");
		else
			System.out.println("Too sweet!");
	}
}
