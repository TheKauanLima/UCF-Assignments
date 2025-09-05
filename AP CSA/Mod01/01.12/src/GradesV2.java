
/**
 * Purpose: Evaluate the total score and averages of different tests
 * 
 * @author Kauan Lima
 * @version 06/12/23
 */
public class GradesV2
{
    public static void main(String[ ] args)
    {
    	//local variables       
        int numTests = 0;		//counts number of tests
        int testGrade = 0;		//individual test grade
        int totalPoints = 0;	//total points for all tests
        double average = 0.0;	//average grade 
        
        //calculate grades, total points, and average on 'x' tests
        numTests++;							//current number of tests
        testGrade = 95;      				//set test grade
        totalPoints += testGrade;			//add testGrade to totalPoints each time
        average = totalPoints / (double)numTests;	//calculate the average
        System.out.println("Test # " + numTests + "\tTest Grade: " + testGrade + "\t\tTotal Points: "
        		+ totalPoints + "\tAverage Score: " + average);
        
        //calculate grades, total points, and average on 'x' tests
        numTests++;							//current number of tests
        testGrade = 73;      				//set test grade
        totalPoints += testGrade;			//add testGrade to totalPoints each time
        average = totalPoints / (double)numTests;	//calculate the average
        System.out.println("Test # " + numTests + "\tTest Grade: " + testGrade + "\t\tTotal Points: "
        		+ totalPoints + "\tAverage Score: " + average);
        
        //calculate grades, total points, and average on 'x' tests
        numTests++;							//current number of tests
        testGrade = 91;      				//set test grade
        totalPoints += testGrade;			//add testGrade to totalPoints each time
        average = totalPoints / (double)numTests;	//calculate the average
        System.out.println("Test # " + numTests + "\tTest Grade: " + testGrade + "\t\tTotal Points: "
        		+ totalPoints + "\tAverage Score: " + average);
        
        //calculate grades, total points, and average on 'x' tests
        numTests++;							//current number of tests
        testGrade = 82;      				//set test grade
        totalPoints += testGrade;			//add testGrade to totalPoints each time
        average = totalPoints / (double)numTests;	//calculate the average
        System.out.println("Test # " + numTests + "\tTest Grade: " + testGrade + "\t\tTotal Points: "
        		+ totalPoints + "\tAverage Score: " + average); 
        
        //calculate grades, total points, and average on 'x' tests
        numTests++;							//current number of tests
        testGrade = 71;      				//set test grade
        totalPoints += testGrade;			//add testGrade to totalPoints each time
        average = totalPoints / (double)numTests;	//calculate the average
        System.out.println("Test # " + numTests + "\tTest Grade: " + testGrade + "\t\tTotal Points: "
        		+ totalPoints + "\tAverage Score: " + average);
        
        //calculate grades, total points, and average on 'x' tests
        numTests++;							//current number of tests
        testGrade = 79;      				//set test grade
        totalPoints += testGrade;			//add testGrade to totalPoints each time
        average = totalPoints / (double)numTests;	//calculate the average
        System.out.println("Test # " + numTests + "\tTest Grade: " + testGrade + "\t\tTotal Points: "
        		+ totalPoints + "\tAverage Score: " + average); 
    }//end of main method
}//end of class