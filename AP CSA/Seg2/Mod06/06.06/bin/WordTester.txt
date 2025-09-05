/**
 * @purpose: Create a method to check whether a string has a certain target word 
 * and also a method to check if the number of words matches with the variable numWords.
 * 
 * @author Kauan Lima
 * @version 1/16/2024
 */
public class WordTester
{
	/*
	 //instance variable myWords contains an array of String values
	storing the words from the phrase - where each element is a
	single word.
	// The instance variable myNumWords acts as a check digit to confirm
	the number of words found in the phrase.
	// The instance variable myTargetWord contains a target word is to
	be located in the array
	// The constructor accepts a String array with the words, an int
	representing the number of words in the phrase and a String
	representing the target word.
	// There may be other instance variables, constructors and methods
	not shown
	*/
	
	private String [] myWords;
	private int myNumWords;
	private String myTargetWord;
	
	public WordTester(String [] words, int numWords, String targetWord)
	{

		myWords = words;
		myNumWords = numWords;
		myTargetWord = targetWord;
	}
	
	public boolean isWithin()
	{
		//check for each element
		for (int i = 0; i < myWords.length; i++)
		{		
			//check if the element and target word matches (ignoring case) and return true
			if(myWords[i].compareToIgnoreCase(myTargetWord) == 0) return true;
		}
		
		return false;
	}
	
	public boolean sameNumber()
	{
		//check if the array length and myNumWords matches and return true
		if (myWords.length == myNumWords) return true;
		
		return false;
	}
}
