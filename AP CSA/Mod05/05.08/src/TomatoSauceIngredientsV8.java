/**
 * Purpose: Construct a new class with default and overloaded methods and constructors to use in TomatoSauceIngredientsTesterV8.
 * 
 * @author Kauan Lima
 * @version 11/29/2023
 */
public class TomatoSauceIngredientsV8
{
	//declare private instance variables
	private int pinches;
	private double cups;
	
	//constructors
	//default constructor for the TomatoSauceIngredientsV3 class
	public TomatoSauceIngredientsV8()
	{
		
	}

	//overloaded constructors
	public TomatoSauceIngredientsV8(double c)
	{
		pinches = 0;
		cups = c;
	}
	
	public TomatoSauceIngredientsV8(int p, double c)
	{
		pinches = p;
		cups = c;
	}
	
	//getters and setters
	public int getPinches()
	{
		return pinches;
	}
	
	public double getCups()
	{
		return cups;
	}
	
	public void setPinches(int p)
	{
		pinches = p;
	}
	
	public void setCups(double c)
	{
		cups = c;
	}
	
	//creating methods
	//method for salt
	public void salt()
	{
		System.out.println("No salt was added! ");
	}
	
	//overloaded method for determining the right amount of salt used
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
