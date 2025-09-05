/**
 * Purpose: Utilize the TomatoSauceIngredients object created by me.
 * Pass in user-inputed variables into the object.
 * 
 * @author Kauan Lima
 * @version 9/17/2023
 */
import java.util.Scanner;
public class TomatoSauceIngredientsTesterV3
{
	TomatoSauceIngredientsV3 pastaSauce = new TomatoSauceIngredientsV3();
	public static void printSeasoning(int salt, double sofrito)
	{
		System.out.println("Sauce has " + salt + " pinches of salt and " + sofrito + " cups of sofrito.");
	}
	
	public static void main(String[] args)
	{
		//initialize scanner
		Scanner in = new Scanner(System.in);
		//initialize my new object
		TomatoSauceIngredientsV3 pastaSauce = new TomatoSauceIngredientsV3();
		
		//prompt for pinches of salt
		System.out.print("How many pinches of salt will you add (Type in a whole number)? ");
		int pinches = in.nextInt();
		
		//prompt for number of cups
		System.out.print("How many cups of sofrito will you add (Type in a double value)? ");
		double cups = in.nextDouble();
		
		//output the results of the seasoning
		System.out.println("");
		printSeasoning(pinches, cups);
		System.out.println("How does your Tomato sauce taste?\n...\n...");
		pastaSauce.salt(pinches);
		
		pastaSauce.sofrito(cups);
		
	}

}
