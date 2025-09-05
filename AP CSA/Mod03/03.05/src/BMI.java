/**
 * Calculate the BMI of an individual given the parameters they assigned
 * 
 * @author Kauan Lima
 * @version 7/22/2023
 */
import java.util.Scanner;
public class BMI
{
	
	public static void main(String[] args)
	{
		//add Scanner object
		Scanner in = new Scanner(System.in);
		
		//first half
		//prompt for first and last name
		System.out.print("Enter your name (first last): ");
		String firstName = in.next();
		String lastName = in.nextLine();
		System.out.println();
		
		//prompt for weight in pounds
		System.out.print("Enter your weight in pounds (e.g. 175): ");
		String weight = in.next();
		System.out.println();
		
		//prompt for height in feet and inches
		System.out.print("Enter your height in feet and inches (e.g. 5 11): ");
		String heightFeet = in.next();
		String heightInches = in.nextLine();
		System.out.println("\n");
		
		//separate the rest of the program
		System.out.println("Body Mass Index Calculator");
		System.out.println("==========================");
		
		//second half
		//display name
		System.out.println("Name: " + firstName + " " + lastName);
		
		//display height
		//set variables
		double heightFeetToInches;
		double convertInchesToCentimeters;
		double heightMeters;
		
		//conversions
		heightFeetToInches = (Double.parseDouble(heightFeet)) * 12;
		
		convertInchesToCentimeters = Double.parseDouble(heightInches);
		convertInchesToCentimeters += heightFeetToInches;
		convertInchesToCentimeters = convertInchesToCentimeters * 2.54;
		
		//add all the conversions together
		heightMeters = convertInchesToCentimeters / 100;
		
		System.out.printf("Height (m): %.1f", heightMeters);
		System.out.println();
		
		//display weight
		double weightLb = Double.parseDouble(weight);
		double weightKg = weightLb * 0.45359237;
		
		System.out.printf("Weight (kg): %.1f", weightKg);
		System.out.println();
		
		//display BMI
		double BMI = weightKg / Math.pow(heightMeters, 2);
		System.out.printf("BMI: %.1f", BMI);
		System.out.println();
		
		//display category
		String category;
		
		if (BMI < 18.5)
			category = "Underweight";
		else if (BMI < 25)
			category = "Healthy Weight";
		else if (BMI < 30)
			category = "Overweight";
		else
			category = "Obese";
		
		System.out.println("Category: " + category);
	}

}
