import java.util.ArrayList;

public class ElectionTesterV2
{
	public static void main(String[] args)
	{
		ArrayList<Candidate> candidate = new ArrayList<Candidate>();

        // create candidates
        candidate.add( new Candidate("Tony Stark", 3691));
        candidate.add( new Candidate("Henry Pym", 2691));
        candidate.add( new Candidate("Billy Burndy", 1962));
        candidate.add( new Candidate("Siraj Rajinthe", 1491));
        candidate.add( new Candidate("Cole Dawkson", 1968));

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
	
	public static void printCandidate(ArrayList<Candidate> candidateList)
    {
        for(Candidate list : candidateList)
           System.out.println(list);
    }
	
	public static int totalVotes(ArrayList<Candidate> candidateVotes)
	{
		int totalVotes = 0;
		for(Candidate votes : candidateVotes)
		{
			totalVotes += votes.getVotes();
		}
		return totalVotes;
	}
	
	public static void candidateData(ArrayList<Candidate> data, int totalVotes)
	{
		double percentVotes = 0;
		for (Candidate row : data)
		{
			percentVotes = (row.getVotes() / (double)totalVotes) * 100;
			System.out.printf("%-19s %-18d %.2f %n", row.getName(), row.getVotes(), percentVotes);
		}
	}
}
