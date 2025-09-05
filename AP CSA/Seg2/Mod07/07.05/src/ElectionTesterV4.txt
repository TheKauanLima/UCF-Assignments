/**
 * @purpose: Display candidates and vote data. Manipulate the candidates and votes with ArrayLists.
 * @author Kauan Lima
 * @version 2/18/2024
 */
import java.util.ArrayList;

public class ElectionTesterV4
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
        
        //manipulate a candidate's name
        //set target and replacement names
        String targetName = "Bruce Banner";
        String newName = "Stan Lee";
        
        //notify and proceed with the change
        System.out.println("<< Changing " + targetName + " to " + newName + " >>\n");
        nameChange(candidate, targetName, newName);
        
        //display the new information
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
        
        //manipulate a candidate's votes
        //set target and replacement names
        targetName = "Henry Pym";
        int newVotes = 284;
        
        //notify and proceed with the change
        System.out.println("<< Changing " + targetName + " votes to " + newVotes + " >>\n");
        voteChange(candidate, targetName, newVotes);
        totalVotes = totalVotes(candidate);
        
        //display the new information
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
        
        //manipulate a whole row of data
        targetName = "Steve Rogers";
        newName = "Yuji Itadori";
        newVotes = 419;
        
        //notify and proceed with the changes
        System.out.println("<< Changing " + targetName + " to " + newName + " and recieving " + newVotes + " votes >>\n");
        candidateChange(candidate, targetName, newName, newVotes);
        totalVotes = totalVotes(candidate);
        
        //display the new information
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
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
}
