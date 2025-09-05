import java.nio.channels.ClosedByInterruptException;

/**
 * @purpose: Display candidates and vote data. Manipulate the candidates and votes with arrays.
 * @author Kauan Lima
 * @version 2/18/2024
 */
public class ElectionTesterV5
{
	public static void main(String[] args)
	{
		//initialize candidate array
		Candidate[] candidate = new Candidate[5];

        // create candidates
        candidate[0] = new Candidate("Tony Stark", 751);
        candidate[1] = new Candidate("Henry Pym", 496);
        candidate[2] = new Candidate("Bruce Banner", 303);
        candidate[3] = new Candidate("Steve Rogers", 225);
        candidate[4] = new Candidate("Claire Dearing", 81);
        
        //print original results and data
        System.out.println("Original Results: \n");
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        
        int totalVotes = totalVotes(candidate);
        
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
        System.out.println();
        
        
        //print out inserted data at a specified position
        int position = 2;
        String newCandidate = "Nick Fury";
        int newVotes = 518;
        
        insertCandidate1(candidate, position, newCandidate, newVotes);
        System.out.println("<< In position " + position + ", add " + newCandidate + ", " + newVotes + " votes >>\n");
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        
        totalVotes = totalVotes(candidate);
        
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
        System.out.println();
        
        
        //print out inserted data before a specified element
        String targetName = "Bruce Banner";
        newCandidate = "Clint Barton";
        newVotes = 426;
        
        insertCandidate2(candidate, targetName, newCandidate, newVotes);
        System.out.println("<< Before " + targetName + ", add " + newCandidate + ", " + newVotes + " votes >>\n");
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        
        totalVotes = totalVotes(candidate);
        
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
	}
	
	//calculate the total number of votes
	public static int totalVotes(Candidate[] candidateVotes)
	{
		int totalVotes = 0;
		for(int i = 0; i < candidateVotes.length; i++)
		{
			totalVotes += candidateVotes[i].getVotes();
		}
		return totalVotes;
	}
	
	//display candidate data
	public static void candidateData(Candidate[] data, int totalVotes)
	{
		double percentVotes = 0;
		for (Candidate row : data)
		{
			percentVotes = (row.getVotes() / (double)totalVotes) * 100;
			System.out.printf("%-19s %3d %20.2f %n", row.getName(), row.getVotes(), percentVotes);
		}
	}
	
	//manipulate candidate name
	public static void nameChange(Candidate[] candidateName, String targetName, String newName)
	{
		for (Candidate names : candidateName)
			if (names.getName() == targetName)	names.setName(newName);
	}
	
	//manipulate candidate votes
	public static void voteChange(Candidate[] candidateVotes, String targetName, int newVotes)
	{
		for (Candidate votes : candidateVotes)
			if (votes.getName() == targetName)	votes.setVotes(newVotes);
	}
	
	//replace candidate
	public static void candidateChange(Candidate[] candidateSwap, String targetName, String newName, int newVotes)
	{
		for (Candidate newCandidate : candidateSwap)
		{
			if (newCandidate.getName() == targetName)
			{
				newCandidate.setName(newName);
				newCandidate.setVotes(newVotes);
			}
		}
	}
	
	public static void insertCandidate1(Candidate[] candidateList, int position, String addName, int addVotes)
    {
       //shift array downward, losing the final index
       for(int i = candidateList.length - 1; i > position; i--)
           candidateList[i] = candidateList[i-1];

       candidateList[position] = new Candidate(addName, addVotes);
    }
	
	public static void insertCandidate2(Candidate[] candidateList, String targetName, String addName, int addVotes)
    {
        int position = 0;

        //find the position of the target candidate
        for(int i = 0; i < candidateList.length; i++)
            if(candidateList[i].getName().equals(targetName))
                position = i;

        //shift array downward, losing the final index
        for(int i = candidateList.length - 1; i > position; i--)
            candidateList[i] = candidateList[i-1];

        candidateList[position] = new Candidate(addName, addVotes);
    }
}
