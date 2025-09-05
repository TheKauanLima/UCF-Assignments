/**
 * @purpose: Class to encrypt text 
 * 
 * @author Kauan Lima
 * @version 3/31/2024
 */

public class Encryption
{
	// alphabet
	public static final char[] ALPHABET = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	public static int shiftValue;
	public static char[] cipherAlphabet = ALPHABET;
	
	// Encryption constructor
	public Encryption(int sV)
	{
		shiftValue = sV;
	}
	
	// create an encryption code
	public static char[] cipher()
	{
		// declare changing variable
		int currentChar;
		
		// print alphabet
		System.out.print("Alphabet:   ");
		for (int i = 0; i < ALPHABET.length; i++)
			System.out.print(ALPHABET[i]);
		System.out.println();
		
		// shift alphabet
		System.out.print("Encryption: ");
		for (int i = 0; i < ALPHABET.length; i++)
		{
			currentChar = (int)ALPHABET[i] - shiftValue;
			
			if (currentChar < 97)
				currentChar += 26;
			
			if (currentChar  > 122)
				currentChar -= 26;
			
			cipherAlphabet[i] = (char)currentChar;
			System.out.print(cipherAlphabet[i]);
		}
		
		System.out.println();
		return cipherAlphabet;
	}
	
	public static char[] encrypt(String message)
	{
		// declare encrypted array
		char[] encrypted  = new char[message.length()];
		int currentChar;
		
		// shift alphabet
		for (int i = 0; i < encrypted.length; i++)
		{
			currentChar = (int)message.toCharArray()[i];
			
			if (Character.isLetter((char)currentChar))
			{
				currentChar = (int)message.toCharArray()[i] - shiftValue;
			}
			
			if (Character.isLowerCase((char)currentChar) && Character.isLetter((char)currentChar))
			{
				if (currentChar < 97)
					currentChar += 26;
				
				if (currentChar  > 122)
					currentChar -= 26;
			}
			else if (Character.isUpperCase((char)currentChar) && Character.isLetter((char)currentChar))
			{
				if (currentChar < 65)
					currentChar += 26;
				
				if (currentChar  > 90)
					currentChar -= 26;
			}
			
			encrypted[i] = (char)currentChar;
			System.out.print(encrypted[i]);
		}
		
		System.out.println();
		return encrypted;	
	}
}
