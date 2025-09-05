/**
 * @purpose: Display candidates and vote data. Manipulate the candidates and votes with ArrayLists.
 * @author Kauan Lima
 * @version 2/18/2024
 */
import java.util.ArrayList;
import java.util.List;

public class ElectionTesterV6
{
	public static void main(String[] args)
	{
		ArrayList<Candidate> candidate = new ArrayList<Candidate>();

        // create candidates
        candidate.add( new Candidate("Tony Stark", 751));
        candidate.add( new Candidate("Henry Pym", 496));
        candidate.add( new Candidate("Bruce Banner", 303));
        candidate.add( new Candidate("Steve Rogers", 225));
        candidate.add( new Candidate("Claire Dearing", 81));
        
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
	public static int totalVotes(ArrayList<Candidate> candidateVotes)
	{
		int totalVotes = 0;
		for(Candidate votes : candidateVotes)
		{
			totalVotes += votes.getVotes();
		}
		return totalVotes;
	}
	
	//display candidate data
	public static void candidateData(ArrayList<Candidate> data, int totalVotes)
	{
		double percentVotes = 0;
		for (Candidate row : data)
		{
			percentVotes = (row.getVotes() / (double)totalVotes) * 100;
			System.out.printf("%-19s %3d %20.2f %n", row.getName(), row.getVotes(), percentVotes);
		}
	}
	
	//manipulate candidate name
	public static void nameChange(ArrayList<Candidate> candidateName, String targetName, String newName)
	{
		for (Candidate names : candidateName)
			if (names.getName() == targetName)	names.setName(newName);
	}
		
	//manipulate candidate votes
	public static void voteChange(ArrayList<Candidate> candidateVotes, String targetName, int newVotes)
	{
		for (Candidate votes : candidateVotes)
			if (votes.getName() == targetName)	votes.setVotes(newVotes);
	}
		
	//replace candidate
	public static void candidateChange(ArrayList<Candidate> candidateSwap, String targetName, String newName, int newVotes)
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
	
	public static void insertCandidate1(ArrayList<Candidate> candidateList, int position, String addName, int addVotes)
    {
        // insert item into ArrayList
        candidateList.add(position, new Candidate(addName, addVotes));
    }

    public static void insertCandidate2(ArrayList<Candidate> candidateList, String targetName, String addName, int addVotes)
    {
        int position = 0;

        // find location of item you want to insert before
        for(int i = 0; i < candidateList.size(); i++)
            if(candidateList.get(i).getName().equals(targetName))
                position = i;

        // insert item into ArrayList
        candidateList.add(position, new Candidate(addName, addVotes));
    }
}
