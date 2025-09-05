/**
 * @purpose:  This class defines a Student by their name and quiz scores.
 *
 * @author Kauan Lima
 * @version 2/25/24
 */

public class Student
{
    // instance variables
    private int quiz1;
    private int quiz2;
    private int quiz3;
    private int quiz4;
    private int quiz5;
    private String studentName;

    // Constructor for objects of class student
    public Student(String name, int q1, int q2, int q3, int q4, int q5)
    {
        // initialize instance variables
        studentName = name;
        quiz1 = q1;
        quiz2 = q2;
        quiz3 = q3;
        quiz4 = q4;
        quiz5 = q5;
    }

    public String getName()
    {
        return studentName;
    }

    public int getQuiz1()
    {
        return quiz1;
    }
    
    public int getQuiz2()
    {
        return quiz2;
    }
    
    public int getQuiz3()
    {
        return quiz3;
    }
    
    public int getQuiz4()
    {
        return quiz4;
    }
    
    public int getQuiz5()
    {
        return quiz5;
    }

    public void setQuiz1(int q1)
    {
        quiz1 = q1;
    }
    
    public void setQuiz2(int q2)
    {
        quiz2 = q2;
    }
    
    public void setQuiz3(int q3)
    {
        quiz3 = q3;
    }
    
    public void setQuiz4(int q4)
    {
        quiz4 = q4;
    }
    
    public void setQuiz5(int q5)
    {
        quiz5 = q5;
    }

    public void setName(String n)
    {
        studentName = n;
    }

    public String toString()
    {
        return studentName + "\t\t" + quiz1 + "\t" + quiz2 + "\t" + quiz3 + "\t" + quiz4 + "\t" + quiz5 + "\n";
    }
}
