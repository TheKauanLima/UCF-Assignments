import java.util.Random;

/**
 * Purpose: generate a random number and perform various operations, such as reversal,
 * 			subtraction, multiplication, concatenating, changing to string, and parsing.
 * 
 * @author Kauan Lima
 * @version 8/20/23
 *
 */
public class MathTrick {
	
	/**
	 * 
	 ******  DO NOT USE ARRAYS OR CONVERT NUMBERS TO STRING UNTIL STEP 7 ******
	 *
	 */
	
	// Step 1) Creates a random 3 digit (100-999) number where the first and last digit differ by more than one
	// Hint: Use Math.random() to create number in the correct range
	// 		 use modulus to find the last digit and divide by 100 for the first digit.
	//		 calculate the difference, which method can you use so it doesn't matter how the numbers are subtract?
	// 		 while the difference of the digits is less than 2, create a new random number and try again

	public static int getRandomNum() 
	{	int num = 0;
		int firstDigit = 0;
		int lastDigit = 0;

		// complete the method
		//initialize variables
		//difference and range
		int differenceCheck = 0;
		int rangeNeg = -2;
		int rangePos = 2;
		
		//math.random bounds
		int upperBound = 1000;
		int lowerBound = 100;
		
		//calculatory variables
		int findFirstDigit = 100;
		int findDividend = 10;
		int findLastDigit = 0;
		
		//loop condition
		boolean trueVal = true;
		
		while (trueVal)
		{
			//generate random number
			num = (int)(Math.random() * (upperBound - lowerBound)) + lowerBound;
			
			//find first digit
			firstDigit = num / findFirstDigit;
			
			//find last digit
			findLastDigit = num / findDividend;
			lastDigit = num % findLastDigit;
			
			//take the difference
			differenceCheck = firstDigit - lastDigit;
			
			//determine range
			//if the difference is less than +2
			if (differenceCheck < rangePos)
			{
				//if the difference is less than -2, do not continue loop
				if(differenceCheck < rangeNeg)
					trueVal = false;
				//if the difference is -2, do not continue loop
				else if (differenceCheck == -2)
					trueVal = false;
				//otherwise, continue loop once more
				else
					continue;
			}
			//otherwise, do not continue the loop
			else
				trueVal = false;
		}

		return num;
	}

	// Step 2 & 4) reverse the digits of a number
	// Hint: to reverse a number without converting it to a String:
	//		create a new variable to store the reversed number
	//		while the original number > 0
	//		for each digit, multiply the new variable by 10 (to make room for the new digit) 
	//		then add the last digit (remember modulus?) to the new variable
	//		divide the original number by 10 to get rid of the last digit
	//	Ex: 584--> (0 x 10) + 4 = 4 ; 58--> (4 x 10) + 8 = 48; 5-->(48 x 10) + 5 = 485

	public static int reverseDigits (int num)
	{
		// complete the method
		//initialize variables
		//number given
		int normalNum = num;
		
		//calculatory numbers
		int findDividend = 10;
		int findLastDigit = 100;
		int lastDigit = 0;
		int firstDigit = 0;
		int newDividend = findLastDigit;
		int normalNumDividend = 10;
		
		//number to store the final number in between iterations
		int storeNum = 0;
		
		//final reversed number
		int reversed = 0;
		
		//start calculation
		//repeat until the number ends
		while (normalNum > 0)
		{
			//check for length of number, and change conditions based on length
			//find the last digit by removing the last digit first
			if (normalNum > 99)
				findLastDigit = normalNum / findDividend;
			//if number is less than 100, find the last digit by taking the modulus of firstDigit * 10
			else if (normalNum > 9)
			{
				firstDigit = normalNum / 10;
				newDividend = firstDigit * 10;
				findLastDigit = normalNum % newDividend;
			}
			//reset findLastDigit
			else
				findLastDigit = 0;
			
			//if findLastDigit > 0, calculate within
			if (findLastDigit > 0)
			{
				//if digit is a single number, make lastDigit equal to findLastDigit
				if (findLastDigit < 10)
					lastDigit = findLastDigit;
				//if digit isn't singular, calculate normally
				else
					lastDigit = normalNum % findLastDigit;
			}
			//calculate the lastDigit, accounting for if findLastDigit is at 0 at any other point of the process
			else
			{
				if (normalNum == newDividend)
					lastDigit = findLastDigit;
				else
					lastDigit = normalNum;
			}
			
			//store the reversed number several times until storeNum is equal to the lastDigit
			reversed = ((storeNum * 10) + lastDigit);
			
			storeNum = reversed;
			
			//shorten normalNum with each iteration
			normalNum = normalNum / normalNumDividend;
		}
		
		return reversed;
	}
	
	// Step 7) replace characters in a String according to the chart
	// Hint: Loop through the String and "replace" the numbers with the corresponding letter
	public static String replaceLtr(String str)
	{
		// complete the method
		//initialize string and empty char array
		String letters = str;
		char[] toChar = new char[str.length()];
		
		//check for which number will correspond to which letter
		for (int i = 0; i < str.length(); i++)
		{
			toChar[i] = letters.charAt(i);
			
			if (toChar[i] == '0')
				toChar[i] = 'Y';
			else if (toChar[i] == '1')
				toChar[i] = 'M';
			else if (toChar[i] == '2')
				toChar[i] = 'P';
			else if (toChar[i] == '3')
				toChar[i] = 'L';
			else if (toChar[i] == '4')
				toChar[i] = 'R';
			else if (toChar[i] == '5')
				toChar[i] = 'O';
			else if (toChar[i] == '6')
				toChar[i] = 'F';
			else if (toChar[i] == '7')
				toChar[i] = 'A';
			else if (toChar[i] == '8')
				toChar[i] = 'I';
			else
				toChar[i] = 'B';
		}
		
		//convert the char array to a string
		String lettersConverted = String.valueOf(toChar);
		
		return lettersConverted;
	}
	
	// Step 8) reverse the letters in a String
	// Hint: start with an empty String variable 
	//		 loop through the original word   
	//		 add one letter at time to the new variable using concatenation and .substring()
	public static String reverseString(String str)
	{
		// complete the method
		//initialize string variables
		String normalString = str;
		String reversedString = "";
		
		//swap the beginning with the end using i
		for(int i = normalString.length() - 1; i >=0; i--)
			reversedString += normalString.charAt(i);
			
		return reversedString;
	}
		
	public static void main(String[] args) 
	{
//		1.	Generate a random 3-digit number so that the first and third digits differ by more than one.
		int startingNum = getRandomNum();
		System.out.println("1. The starting number: " + startingNum);
		
//		2.	Now reverse the digits to form a second number.
		int reverseNum = reverseDigits(startingNum);
		System.out.println("2. The reversed number: " + reverseNum);
		
//		3.	Subtract the smaller number from the larger one.
		int difference = 0;
		
		//check which num is larger and then subtract
		if (startingNum < reverseNum)
			difference = reverseNum - startingNum;
		else
			difference = startingNum - reverseNum;
		
		//print
		System.out.println("3. The difference is: " + difference);
		
//		4.	Now reverse the digits in the answer you got in step 3 and add it to that number.
		int reverseDifference = reverseDigits(difference);
		
		//concatenate
		String diffString = Integer.toString(difference);
		String reverseDiffString = Integer.toString(reverseDifference);
		String concatDiffString = diffString + reverseDiffString;
		
		//print
		System.out.println("4. The reversed number added to the difference: " + concatDiffString);
		
//		5.	Multiply by one million.
		int preMultiply = Integer.parseInt(concatDiffString);
		int multiplied = preMultiply * 1000000;
		System.out.println("5. Number x one million: " + multiplied);
		
//		6.	Subtract 733,361,573.
		int subtracted = multiplied - 733361573;
		String subtractedString = Integer.toString(subtracted);
		
		System.out.println("6. Number subtracted and converted to string: " + subtractedString);
		
//		7.	Convert the number to a string in order to replace the numbers with letters.
// 				Ex: String str = String.valueOf(myNumber);
//			Then, replace each of the digits in your answer, with the letter it corresponds to using the table in the instructions.
		String converted = replaceLtr(subtractedString);
		System.out.println("7. Replaced String: " + converted);
		
//		8.	Now reverse the letters in the string to read your message backward.
		String reversedConverted = reverseString(converted);
		System.out.println("8. Reversed String: " + reversedConverted);
		
	} // end main
} // end class