/**
 * Purpose: Utilize the TomatoSauceIngredientsV8 class to make several scenarios with differently seasoned sauces.
 * 			Make a pasta, pizza, and meatball sauce with different methods found in TomatoSauceIngredientsV8.
 * 
 * @author Kauan Lima
 * @version 11/29/2023
 */
public class TomatoSauceIngredientsTesterV8
{
	public static void printSeasoning(int salt, double sofrito)
	{
		System.out.println("Sauce has " + salt + " pinches of salt and " + sofrito + " cups of sofrito.");
	}
	
	public static void main(String[] args)
	{
		//set variables to use in methods
		int maxValueSaltChef = 6;
		int minValueSaltChef = 2;
		double maxValueSofritoChef = 3.2;
		double minValueSofritoChef = 0.8;
		
		//initialize my new object
		TomatoSauceIngredientsV8 pastaSauce = new TomatoSauceIngredientsV8();
		
		//chef header
		System.out.println("=======================");
		System.out.println("Let's make pasta sauce!");
		System.out.println("=======================\n");
		
		//generate random values
		System.out.println("A master chef has come in to help you with your pasta sauce! ");
		pastaSauce.setPinches((int)(Math.random() * (maxValueSaltChef-minValueSaltChef) + minValueSaltChef));
		pastaSauce.setCups(Math.random() * (maxValueSofritoChef-minValueSofritoChef) + minValueSofritoChef);
		
		//display random values
		System.out.println("The master chef used " + pastaSauce.getPinches() + " pinches of salt and " + pastaSauce.getCups() + " cups of sofrito!");
		System.out.println("...\n...");
		
		//calculate whether the chef used the right amount of salt and sofrito
		pastaSauce.salt(pastaSauce.getPinches());
		pastaSauce.sofrito(pastaSauce.getCups());
		if(pastaSauce.getPinches() < 3 || pastaSauce.getPinches() > 5 || pastaSauce.getCups() < 1 || pastaSauce.getCups() >= 3)
			System.out.println("The master chef has been fired!");
		else System.out.println("The master chef is amaster of his craft.");
		
		
		//separate the chef and monkey
		System.out.println("\n");

		System.out.println("=======================");
		System.out.println("Let's make pizza sauce!");
		System.out.println("=======================\n");
		
		//initialize a second object
		TomatoSauceIngredientsV8 pizzaSauce = new TomatoSauceIngredientsV8(2.0);
		int maxValueSaltMonkey = 8;
		int minValueSaltMonkey = 0;
		double chanceValue = (Math.random() * (100));
		System.out.println(chanceValue);
		System.out.println("As you add in the sofrito, a monkey runs into the kitchen and starts throwing salt in your sauce! ");
		
		if (chanceValue < 50)
		{
			//generate a random value
			pizzaSauce.setPinches((int)(Math.random() * (maxValueSaltMonkey-minValueSaltMonkey) + minValueSaltMonkey));
			
			//display random value
			System.out.println("The monkey threw " + pizzaSauce.getPinches() + " pinches of salt in your sauce!");
			System.out.println("...\n...");
			//calculate whether the monkey threw the right amount of salt
			if(pizzaSauce.getPinches() < 3 || pizzaSauce.getPinches() > 5)
				System.out.println("The monkey has ruined your sauce.\n\n");
			else System.out.println("It tastes wonderful! The monkey is surprisingly gifted.\n\n");
		}
		else
		{
			pizzaSauce.salt();
			System.out.println("The monkey missed all the salt! You now add the perfect amount and enjoy your delicious pizza sauce.\n\n");
		}
		
		//separate the monkey and you
		System.out.println("=======================");
		System.out.println("Let's make meatball sauce!");
		System.out.println("=======================\n");
		
		TomatoSauceIngredientsV8 meatballSauce = new TomatoSauceIngredientsV8(4, 2.0);
		
		System.out.println("You can finally make your own sauce in peace.");
		System.out.println("...\n...");
		meatballSauce.salt(meatballSauce.getPinches());
		meatballSauce.sofrito(meatballSauce.getCups());
		System.out.println("You enjoy your perfect sauce and meatballs.");
		
	}
}
