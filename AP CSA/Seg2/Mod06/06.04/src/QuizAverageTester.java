/**
 * @purpose: Tester to create an array of QuizAverage objects. Prints the data calculated in the object onto the console.
 *
 * @author Kauan Lima
 * @version 1/16/2024
 */
 
 
public class QuizAverageTester
{
   
   public static void main (String [] args) {
   
	   //initialize all variables for the objects
       String name1 = "Aaron";
       int quiz1Student1 = 92;
       int quiz2Student1 = 88;
       
       String name2 = "Blake";
       int quiz1Student2 = 78;
       int quiz2Student2 = 85;
       
       String name3 = "Jaqueline";
       int quiz1Student3 = 93;
       int quiz2Student3 = 80;
       
       String name4 = "Denise";
       int quiz1Student4 = 92;
       int quiz2Student4 = 95;
       
       String name5 = "Jacob";
       int quiz1Student5 = 82;
       int quiz2Student5 = 87;
       
       double difference = 0.0;
       double average = 0.0;
       
       //create an array of at least 5 objects
       QuizAverage[] quizzes = {new QuizAverage(name1, quiz1Student1, quiz2Student1),
    		   					new QuizAverage(name2, quiz1Student2, quiz2Student2),
    		   					new QuizAverage(name3, quiz1Student3, quiz2Student3),
    		   					new QuizAverage(name4, quiz1Student4, quiz2Student4),
    		   					new QuizAverage(name5, quiz1Student5, quiz2Student5)};
     
       //print out header
       System.out.println("                               Quiz Results");
       System.out.printf("%s %15s %15s %15s %15s %n", "Student Name", "Quiz1 Grade", "Quiz2 Grade", "Difference", "Average");
       System.out.println("==============================================================================");
       
       //prints the QuizAverage array of objects using the toString() method
       for(QuizAverage q: quizzes)
       {
         difference = q.calcDifference();
         average = q.calcAverage();
         System.out.print(q);
         System.out.printf("%20.2f %18.2f %n", difference, average);
       }
   }
}
