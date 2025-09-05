
public class WordCheckerTester
{
	public static void main(String[] args)
	{
		String input = "Imagine if Ninja got a low taper fade.";
		
		String[] words = input.split(" ");
		int numWords = 8;
		String targetWord = "nInja";
		
		WordTester tester = new WordTester(words, numWords, targetWord);
		
		tester.isWithin();
		tester.sameNumber();
	}
}
