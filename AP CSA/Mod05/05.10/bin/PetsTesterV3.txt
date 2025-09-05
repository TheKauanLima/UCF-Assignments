import java.util.Scanner;

/**
 * Purpose: prompt the user various questions about what kind of pet they'd like, use the "Pets" class to create an object
 * 			Ask the user whether they want to keep repeating the program to create new pets.
 * 
 * @author Kauan Lima
 * @version 12/1/2023
 */
public class PetsTesterV3
{
	
	public static void main(String[] args)
	{
		//add scanner object
		Scanner in = new Scanner(System.in);
		
		//declare variables for later use
		String petName;
		String petBreed;
		String petAgeString;
		int confirmationCode;
		
		//for loop to repeat the code if needed.
		for (int i = 1; i > 0; i++)
		{
			//prompt user for pet information
			System.out.print("What is the name of the pet? ");
			petName = in.next();
			System.out.println();
			
			System.out.print("What is the breed of the pet? ");
			petBreed = in.next();
			System.out.println();
			
			System.out.print("How old is the pet? ");
			petAgeString = in.next();
			System.out.println();
			
			int petAge = Integer.parseInt(petAgeString);
			
			//display pet information
			System.out.println("Pet Info: \tName\tBreed\tAge");
			System.out.println("======================================================");
			
			//create a pet
			PetsV3 newPet = new PetsV3(petName, petBreed, petAge);
			
			System.out.println("Pet " + i + ": \t\t" + newPet.getName() + ",\t" + newPet.getBreed() + ",\t" + newPet.getAge() );
			System.out.println();
			
			//ask user to repeat the program
			confirmationCode = 0;
			while (confirmationCode == 0)
			{
				System.out.print("Would you like to create another pet? (yes/no) ");
				char confirmation = in.next().charAt(0);
				System.out.println();
				
				if (!(confirmation == 'n' || confirmation == 'y'))
				{
					System.out.println("Please enter a valid response");
				}
				else if (confirmation == 'n')
				{
					System.out.println("goodbye!");
					System.exit(0);
				}
				else	confirmationCode = 1;
			}
		}
	}
}
