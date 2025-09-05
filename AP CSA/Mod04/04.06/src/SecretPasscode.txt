/**
 * Purpose: Randomly generate passwords.
 *
 * @author Kauan Lima
 * @version 8/13/2023
 * 
 */
import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.util.Scanner;

public class SecretPasscode
{
    public static void main(String [] args) throws IOException
    {
    	//initialize variables
    	//user decision for whether or not to generate more passwords
        String userChoice = "Y";
        //password length
        int pwLength = 0;
        //random number
        int randNum = 0; 
        //final password
        String password = "";
        
        //number of passwords
        int passCount = 0;
        
        //generation of passwords: check for which type of character a given char will be
        boolean isNum = false;
        boolean isLower = false;
        boolean isUpper = false;
        
        //generation of passwords: decides which character a char will be
        int randNumForNum = 0;
        int randNumForLower = 0;
        int randNumForUpper = 0;
        
        //always true condition to check for validation
        boolean whileCondition = true;
        
        //to validate the userChoice char
        int charChecker = 0;

        // initialize scanner and print writer
        Scanner in = new Scanner(System.in);
        File inFile = new File("password.txt");
        PrintWriter outFile = new PrintWriter(inFile);
        Scanner scan = new Scanner(inFile);

        //program header
        System.out.println("**********************************************************");
        System.out.println("Welcome to a simple password generator. \nThe password will include lowercase, uppercase, & numbers.");
	    
        //begin program/restart program
        // the user wants to continue
        while (userChoice.charAt(0) == 'Y')
        {
        	//check for the number of passwords
        	passCount++;
        	
        	// Ask for password length 
            System.out.print("Enter a password length (6 or more): ");
            pwLength = in.nextInt();
            System.out.println();
            
            
            // validate password length
            while (pwLength < 6)
            {
            	//notify user that password length is too short
            	System.out.println("\tPassword length too short. Please try again.");
            	
            	//reprompt
            	System.out.print("Enter a password length (6 or more): ");
                pwLength = in.nextInt();
                System.out.println();
            }
            
            //initialize char array with pwLength to construct the final password
            char passwordCharArray[] = new char[pwLength];
    		
            // generate a random character in the correct character set
    		for (int i = 0; i < pwLength; i++)
    		{
    			//reset values
    			isNum = false;
    			isLower = false;
    			isUpper = false;
    			
    			//decide whether a char will be a number, lowercase, or uppercase
    			//randomly generate a number
    			randNum = (int)(Math.random() * 100) + 1;
    	        
    			//if randNum is anywhere from [1-33], the char is a number
    			if (randNum <= 33)
    			{
    				isNum = true;
    			}
    			//if randNum is anywhere from [34-66], the char is a lowercase letter
    			else if (randNum <= 66)
    			{
    				isLower = true;
    			}
    			//if randNum is anywhere from [67-99], the char is an uppercase letter
    			else if (randNum <= 99)
    			{
    				isUpper = true;
    			}
    			
    			//if the char is a number, it can be any value from 0-9
    			if (isNum)
    			{
    				randNumForNum = (int)(Math.random() * 10) + 48;
    				passwordCharArray[i] = (char)(randNumForNum);
    			}
    			//if the char is a lowercase letter, it can be any letter from a-z
    			else if (isLower)
    			{
    				randNumForLower = (int)(Math.random() * 26) + 97;
    				passwordCharArray[i] = (char)(randNumForLower);
    			}
    			//if the char is an uppercase letter, it can be any letter from A-Z
    			else if (isUpper)
    			{
    				randNumForUpper = (int)(Math.random() * 26) + 65;
    				passwordCharArray[i] = (char)(randNumForUpper);
    			}
    		}
    		
    		// concatenate the character to the password
    		//variable that remembers what came before the current char is passwordCharArray[pwLength]
    		String tempPass = "";
    		
    		//refresh the password if the user decides to continue
    		password = "";
    		
    		//after each iteration, the final password gets 1 char added
    		for(int i = 0; i < pwLength; i++)
    		{
    			//temporary password to remember what comes before the current char
    			tempPass = password;
    			
    			//add the current char to get the final password
    			password = (tempPass + passwordCharArray[i]);
    		}
    		
    		// write the password to the file
    		outFile.println("\t" + passCount + ".\t" + password);
    		System.out.println("A password has been written to the text file");
    		
    		//prompt user to generate new password
    		System.out.print("Would you like to generate another password? Y/N ");
    		userChoice = in.next();
    		System.out.println();
    		
    		//uppercase the result
    		userChoice = userChoice.toUpperCase();
    		
    		//check whether answer is a Y or N
    		if (userChoice.charAt(0) == 'Y')
    			charChecker = 1;
    		else if (userChoice.charAt(0) == 'N')
    			charChecker = 1;
    		else
    			;
    		
    		//check for correct conditions
    		while (whileCondition)
    		{
    			//if userChoice is longer than 1, reprompt
    			if (userChoice.length() != 1)
        		{
        			System.out.print("Please enter a single character. Y/N ");
        			userChoice = in.next();
            		System.out.println();
            		continue;
        		}
        		
    			//if userChoice isn't either Y or N, reprompt
        		if(charChecker == 0)
        		{
        			
        			System.out.println(userChoice);
            		System.out.println("Please enter an acceptable character. Y/N ");
            		userChoice = in.next();
                	System.out.println();
                	continue;
        		}
        		
        		//if all criteria match, the answer is valid
        		if(charChecker == 1)
        			break;
    		}
    		
    		//if answer is Y, continue the loop again
    		if (userChoice.charAt(0) == 'Y')
    			continue;
        }
        // when the user is done, close the text file so that it can be re-opened and read
        outFile.close();
        
        // Read passwords back from text file and display to the screen
        System.out.println("Thank you for using the Pass Code Generator.\n");
        System.out.println("Here are your randomly generated codes:");
        
        while(scan.hasNextLine())
        {
        	System.out.println(scan.nextLine());
        }

  }//end main
}//end class