/**
 * @purpose:
 * @author Kauan Lima
 * @version 2/18/2024
 */
public class ElectionTesterV1
{
	public static void main(String[] args)
	{
		Candidate[] candidate = new Candidate[5];

        // create candidates
        candidate[0] = new Candidate("Tony Stark", 3691);
        candidate[1] = new Candidate("Henry Pym", 2691);
        candidate[2] = new Candidate("Billy Burndy", 1962);
        candidate[3] = new Candidate("Siraj Rajinthe", 1491);
        candidate[4] = new Candidate("Cole Dawkson", 1968);

        System.out.println(" Raw Election Data: \n");
        printCandidate(candidate);
        
        System.out.println();
        System.out.println();
        System.out.println("Election Results: \n");
        System.out.println("                   Votes            % of Total");
        System.out.println("Candidate         Recieved             Votes");
        System.out.println("==============================================");
        
        int totalVotes = totalVotes(candidate);
        
        candidateData(candidate, totalVotes);
        
        System.out.println();
        System.out.println("The total number of votes is: " + totalVotes);
	}
	
	public static void printCandidate(Candidate[] candidateList)
    {
        for(int i = 0; i < candidateList.length; i++)
           System.out.println(candidateList[i]);
    }
	
	public static int totalVotes(Candidate[] candidateVotes)
	{
		int totalVotes = 0;
		for(int i = 0; i < candidateVotes.length; i++)
		{
			totalVotes += candidateVotes[i].getVotes();
		}
		return totalVotes;
	}
	
	public static void candidateData(Candidate[] data, int totalVotes)
	{
		double percentVotes = 0;
		for (Candidate row : data)
		{
			percentVotes = (row.getVotes() / (double)totalVotes) * 100;
			System.out.printf("%-19s %-18d %.2f %n", row.getName(), row.getVotes(), percentVotes);
		}
	}
}
