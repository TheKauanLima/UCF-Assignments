/**
 * @purpose: Display candidates and vote data. Manipulate the candidates and votes with arrays.
 * @author Kauan Lima
 * @version 2/23/2024
 */
public class ElectionTesterV7
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
        System.out.println();
        
        //delete data at a position
        position = 4;
        
        deleteByPostion(candidate, position);
        System.out.println("<< Delete item at position " + position + " >>\n");
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        
        totalVotes = totalVotes(candidate);
        
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
        System.out.println();
        
        //delete data before a specified element
        targetName = "Henry Pym";
        
        deleteByName(candidate, targetName);
        System.out.println("<< Delete " + targetName + " >>\n");
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        
        totalVotes = totalVotes(candidate);
        
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
        System.out.println();
	}
	
	//calculate the total number of votes
	public static int totalVotes(Candidate[] candidateVotes)
	{
		int totalVotes = 0;
		for(int i = 0; i < candidateVotes.length; i++)
		{
			if (candidateVotes[i] != null)
			{
				totalVotes += candidateVotes[i].getVotes();
			}
			else if (candidateVotes[i] == null)
			{
				break;
			}
		}
		return totalVotes;
	}
	
	//display candidate data
	public static void candidateData(Candidate[] data, int totalVotes)
	{
		double percentVotes = 0;
		for (Candidate row : data)
		{
			if (row != null)
			{
				percentVotes = (row.getVotes() / (double)totalVotes) * 100;
				System.out.printf("%-19s %3d %20.2f %n", row.getName(), row.getVotes(), percentVotes);
			}
			else if (row == null)
			{
				break;
			}
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
	
	//method to insert by position
	public static void insertCandidate1(Candidate[] candidateList, int position, String addName, int addVotes)
    {
       //shift array downward, losing the final index
       for(int i = candidateList.length - 1; i > position; i--)
           candidateList[i] = candidateList[i-1];

       candidateList[position] = new Candidate(addName, addVotes);
    }
	
	//method to insert before a target candidate
	public static void insertCandidate2(Candidate[] candidateList, String targetName, String addName, int addVotes)
    {
        int position = 0;

        //find the position of the target candidate
        for(int i = 0; i < candidateList.length; i++)
        {
            if((candidateList[i] != null) & (candidateList[i].getName().equals(targetName)))
            {
                position = i;
                break;
            }
            else if (candidateList[i] == null)
            {
            	position = i;
            	break;
            }
        }

        //shift array downward, losing the final index
        for(int i = candidateList.length - 1; i > position; i--)
            candidateList[i] = candidateList[i-1];

        candidateList[position] = new Candidate(addName, addVotes);
    }
	
	//method to delete by position
	public static void deleteByPostion(Candidate[] candidateList, int position)
    {
        if ((position > 0) && (position < candidateList.length))
        {
            //move candidate up in the array
            for(int i = position; i < candidateList.length -1; i++)
                candidateList[i] = candidateList[i + 1];

            candidateList[candidateList.length-1] = null;
        }
    }
	
	//method to delete by searching for a target name
	public static void deleteByName(Candidate[] candidateList, String targetName)
    {
        int position = 0;
        int i;

        // find position of candidate you want to delete
        for(i = 0; i < candidateList.length; i++)
            if((candidateList[i] != null) && (candidateList[i].getName().equals(targetName)))
            {
                position = i;
                break;
            }
            else if(candidateList[i] == null)
            {
                position = -1;
                break;
            }

        if ((i != candidateList.length) && (position >= 0))
        { 
            //move candidate up in the array
            for(i = position; i < candidateList.length -1; i++)
                candidateList[i] = candidateList[i + 1];

            candidateList[candidateList.length-1] = null;
        }
    }
}
