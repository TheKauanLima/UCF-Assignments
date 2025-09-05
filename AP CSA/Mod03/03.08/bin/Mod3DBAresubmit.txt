/**
 * 
 * @author Kauan Lima
 * @version 7/30/2023
 */
import java.util.Scanner;
public class Mod3DBA
{
	public static void main(String[] args)
	{
		//add scanner
		Scanner in = new Scanner(System.in);
		
		//prompt for information
		//prompt for name
		System.out.print("Please enter your name: ");
		String name = in.nextLine();
		System.out.println();
		
		//prompt for age
		System.out.print("Please enter your age: ");
		String ageValue = in.next();
		System.out.println();
		
		//prompt for First Responder
		System.out.print("Are you a first responder (y/n)? ");
		char firstResponderConfirmation = in.next().charAt(0);
		System.out.println();
		
		//prompt for Veteran
		System.out.print("Are you a veteran (y/n)? ");
		char veteranConfirmation = in.next().charAt(0);
		System.out.println();
		
		
		
		//check for First Responder and Veteran information
		//set variables
		boolean isFirstResponder = false;
		boolean isVeteran = false;
		
		//check for valid character and whether it was y or n: First Responder
		if (firstResponderConfirmation == 'y' || firstResponderConfirmation == 'Y')
			isFirstResponder = true;
		else if (firstResponderConfirmation == 'n' || firstResponderConfirmation == 'N')
			isFirstResponder = false;
		else
		{
			System.out.println("invalid character.");
			System.exit(0);
		}
		
		//check for valid character and whether it was y or n: Veteran
		if (veteranConfirmation == 'y' || veteranConfirmation == 'Y')
			isVeteran = true;
		else if (veteranConfirmation == 'n' || veteranConfirmation == 'N')
			isVeteran = false;
		else
		{
			System.out.println("invalid character.");
			System.exit(0);
		}
		
		
		
		//start calculations
		//parse the age
		int age = Integer.parseInt(ageValue);
		//add a price variable
		double price = 0.0;
		
		//determine price based on age
		if (age < 3)
			price = 2;
		else if (age < 6)
			price = 9;
		else if (age < 19)
			price = 11;
		else
			price = 12;
		
		//check for discount on price if over 18
		int dividend = 2;
		
		if (isFirstResponder == false)
		{
			if (isVeteran && price == 12)
			{
				price /= dividend;
			}
		}
		if (isVeteran == false)
		{
			if (isFirstResponder && price == 12)
			{
				price /= dividend;
			}
		}
		
		//make user ID
		//get the first initial
		String firstInitial = name.substring(0, 1);
		//generate a random number
		int upperBound = 1001;
		int lowerBound = 1;
		int randomNumber = (int)(Math.random() * upperBound) + lowerBound;
		String randomValue = Integer.toString(randomNumber);
		//find where the last name begins
		int spaceIndex = name.indexOf(" ") + 1;
		//concatenate all previous values
		String id = firstInitial + name.substring(spaceIndex) + randomValue;
		
		//call the printTicket function
		printTicket(name, id, price);
	}
	
	public static void printTicket(String name, String id, double price)
	{
		System.out.println("Welcome to the APCS Carnival, " + name + "!");
		System.out.println("Your user ID is " + id);
		System.out.println("The cost of your ticket is $" + price + ".");
		System.out.println("Have a great time at the APCS Carnival today!");
	}
}
