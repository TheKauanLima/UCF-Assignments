/**
 * Find out the TDEE of a person given their BMR, gender, and activity factor
 * 
 * @author Kauan Lima
 * @version 7/22/2023
 */
import java.util.Scanner;
public class TDEE
{

	public static void main(String[] args)
	{
		//prompt for information
		//add scanner
		Scanner in = new Scanner(System.in);
		
		//prompt for name
		System.out.print("Please enter your name: ");
		String firstName = in.next();
		String lastName = in.nextLine();
		
		//prompt for BMR
		System.out.print("Please enter your BMR: ");
		String BMR = in.next();
		
		//prompt for gender
		System.out.print("Please enter your gender (M/F): ");
		String genderChar = in.next();
		
		//check for genderChar length
		if (genderChar.length() > 1)
		{
			System.out.println("This is invalid!");
			System.exit(0);
		}
		
		//uppercase all choices
		genderChar = genderChar.toUpperCase();
						
		//get the first char
		char[] selectedGender = genderChar.toCharArray();
		char genderAnswer = selectedGender[0];
				
		char gender = Character.valueOf(genderAnswer);
		
		if (gender == 'F' || gender == 'M')
			;
		else
		{
			System.out.println("This is invalid!");
			System.exit(0);
		}
		
		
		
		//user menu
		//prompt for Activity Level
		System.out.println("Select Your Activity Level\n"
						 + "[A] Resting (Sleeping, Reclining)\n"
						 + "[B] Sedentary (Restricted Mobility)\n"
						 + "[C] Light (Sitting, Standing)\n"
						 + "[D] Moderate (Light Manual Labor, Dancing, Riding Bike)\n"
						 + "[E] Very Active (Team Sports, Hard Manual Labor)\n"
						 + "[F] Extremely Active (Full-time Athelete, Heavy Manual Labor\n");
		System.out.print("Enter the letter corresponding to your activity level: ");
		String choice = in.next();
		System.out.println("\n");
		
		//check choice
		//check length
		if (choice.length() > 1)
		{
			System.out.println("This is invalid!");
			System.exit(0);
		}
		
		//lowercase all choices
		choice = choice.toLowerCase();
		
		//get the first char
		char[] selectedChoice = choice.toCharArray();
		char choiceAnswer = selectedChoice[0];
		
		char answer = Character.valueOf(choiceAnswer);
		
		//check if the char matches an answer choice
		if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd' || answer == 'e' || answer == 'f')
			;
		else
		{
			System.out.println("This is invalid!");
			System.exit(0);
		}
		
		
		
		
		
		//perform calculations
		//display results
		System.out.println("Your results:");
		
		//find genderChar
		
		
		//display name and gender
		System.out.println("Name: " + firstName + " " + lastName
						 + "\t\tGender: " + gender);
		
		//display BMR and Activity Factor
		double doubleBMR = Double.parseDouble(BMR);
		
		double activityFactor = 0.0;
		
		if (gender == 'F')
		{
			if (answer == 'a')
				activityFactor = 1.0;
			else if (answer == 'b')
				activityFactor = 1.3;
			else if (answer == 'c')
				activityFactor = 1.5;
			else if (answer == 'd')
				activityFactor = 1.6;
			else if (answer == 'e')
				activityFactor = 1.9;
			else
				activityFactor = 2.2;
		}
		if (gender == 'M')
		{
			if (answer == 'a')
				activityFactor = 1.0;
			else if (answer == 'b')
				activityFactor = 1.3;
			else if (answer == 'c')
				activityFactor = 1.6;
			else if (answer == 'd')
				activityFactor = 1.7;
			else if (answer == 'e')
				activityFactor = 2.1;
			else
				activityFactor = 2.4;
		}
		
		System.out.println("BMR: " + doubleBMR + " calories"
						 + "\t\tActivity Factor: " + activityFactor);
		
		//display TDEE
		double TDEE = doubleBMR * activityFactor;
		System.out.println("TDEE: " + TDEE + " calories");
	}
}
