/**
 * @purpose: QuizAverage object class. Made to create the QuizAverage object and intake quiz grades to calculate the difference and averages.
 *
 * @author Kauan Lima
 * @version 1/16/2024
 *
 */
 
 
public class QuizAverage
{
   private String n;
   private int q1;
   private int q2;

     
   
   //one parameter constructor, all private instance variables initialized
   public QuizAverage(String name)
   {
      n = name;
      q1 = 0;
      q2 = 0;
   }

   //two parameter constructor
   public QuizAverage(String name, int quiz1)
   {
      n = name;
      q1 = quiz1;
   }
   
   //three parameter constructor
   public QuizAverage(String name, int quiz1, int quiz2)
   {
      n = name;
      q1 = quiz1;
      q2 = quiz2;
   }
   
   //getters and setters
   public String getName()
   {
      return n; 
   }
   
   public int getQuiz1()
   {
      return q1;  
   }
   
   public int getQuiz2()
   {
	      return q2;  
   }
   
   
   public void setName(String name)
   {
      n = name;
   }
   
   public void setQuiz1(int quiz1)
   {
      q1 = quiz1;
   }
   
   public void setQuiz2(int quiz2)
   {
	      q2 = quiz2;
   }
   
   //difference methods
   public double calcDifference()
   {
       double difference = q2 - q1;
       return difference;
   }
   
   //overloaded difference methods
   public double calcDifference(int q1)
   {
	   double difference = q2 - q1;
       return difference;
   }
   
   public double calcDifference(int q1, int q2)
   {
	   double difference = q2 - q1;
       return difference;
   }
   
   //average methods
   public double calcAverage()
   {
       double average = (q1 + q2) / 2.0;
       return average;
   }
   
   //overloaded average methods
   public double calcAverage(int q1)
   {
	   double average = (q1 + q2) / 2.0;
       return average;
   }
   
   public double calcAverage(int q1, int q2)
   {
	   double average = (q1 + q2) / 2.0;
       return average;
   }

   //formatting method to print final data
   public String toString() {
   
      return String.format("%-10s %8d %15d", getName(), getQuiz1(), getQuiz2());  
   }
    
}
