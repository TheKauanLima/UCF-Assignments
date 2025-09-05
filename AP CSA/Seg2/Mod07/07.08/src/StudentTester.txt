/**
 * @purpose:  Display Student information and manipulate student data
 * @author Kauan Lima
 * @version 2/25/24
 */
import java.util.ArrayList;

public class StudentTester
{
	public static void main(String[] args)
	{
		ArrayList<Student> students = new ArrayList<Student>();

        // create candidates
        students.add( new Student("Jack Heir", 70, 80, 90, 80, 90));
        students.add( new Student("Sandra Toft", 80, 85, 90, 85, 80));
        students.add( new Student("Gabriel Silva", 50, 79, 89, 99, 99));
        students.add( new Student("Takuya Kizishi", 85, 80, 85, 88, 89));
        students.add( new Student("Martha Scoppoli", 70, 70, 90, 70, 80));
        
        //print original results and data
        System.out.println("Starting Gradebook: \n");
        System.out.println("Student name		Q1	Q2	Q3	Q4	Q5");
        System.out.println("============================================================");
        
        studentData(students);
        System.out.println("\n");
        
        //print altered results and data (name)
        nameChange(students, "Sandra Toft", "Historia Reiss");
        System.out.println("<< Change Sandra Toft to Historia Reis >>\n");
        
        System.out.println("Second Gradebook: \n");
        System.out.println("Student name		Q1	Q2	Q3	Q4	Q5");
        System.out.println("============================================================");
        
        studentData(students);
        System.out.println("\n");
        
        
        //print altered results and data (quiz score)
        quizChange(students, "Takuya Kizishi", 4, 89);
        System.out.println("<< Change Takua Kizishi's 4th grade to 89 >>\n");
        
        System.out.println("Third Gradebook: \n");
        System.out.println("Student name		Q1	Q2	Q3	Q4	Q5");
        System.out.println("============================================================");
        
        studentData(students);
        System.out.println("\n");
        
        
        //print altered results and data (new student)
        studentChange(students, "Jack Heir", "Miguel Ferrera", 81, 96, 89, 97, 83);
        System.out.println("<< Swap Jakc Heir with Miguel Ferrera and his quiz grades: 81, 96, 89, 97, 83 >>\n");
        
        System.out.println("Fourth Gradebook: \n");
        System.out.println("Student name		Q1	Q2	Q3	Q4	Q5");
        System.out.println("============================================================");
        
        studentData(students);
        System.out.println("\n");
        
        
        //print altered results and data (insertion)
        insertStudent(students, "Takuya Kizishi", "Kim Sung Woo", 77, 81, 73, 89, 86);
        System.out.println("<< Add Kim Sung Woo before Takua Kizishi with gardes 77, 81, 73, 89, 86 >>\n");
        
        System.out.println("Fifth Gradebook: \n");
        System.out.println("Student name		Q1	Q2	Q3	Q4	Q5");
        System.out.println("============================================================");
        
        studentData(students);
        System.out.println("\n");
        
        
        //print altered results and data (deletion)
        deleteStudent(students, "Gabriel Silva");
        System.out.println("<< Delete Gabriel Silva's records >>\n");
        
        System.out.println("Sixth Gradebook: \n");
        System.out.println("Student name		Q1	Q2	Q3	Q4	Q5");
        System.out.println("============================================================");
        
        studentData(students);
        System.out.println("\n");
	}
	
	//display student data
	public static void studentData(ArrayList<Student> data)
	{
		for (Student row : data)
			System.out.print(row);
	}
		
	//manipulate student name
	public static void nameChange(ArrayList<Student> studentName, String targetName, String newName)
	{
		for (Student names : studentName)
			if (names.getName() == targetName)	names.setName(newName);
	}
			
	//manipulate student votes
	public static void quizChange(ArrayList<Student> studentQuiz, String targetName, int quizNum, int newQuizScore)
	{
		for (Student quiz : studentQuiz)
		{
			//check for target student
			if (quiz.getName() == targetName)
			{
				//replace score
				if (quizNum == 1) quiz.setQuiz1(newQuizScore);
				else if (quizNum == 2) quiz.setQuiz2(newQuizScore);
				else if (quizNum == 3) quiz.setQuiz3(newQuizScore);
				else if (quizNum == 4) quiz.setQuiz4(newQuizScore);
				else if (quizNum == 5) quiz.setQuiz5(newQuizScore);
			}
		}
	}
			
	//replace student
	public static void studentChange(ArrayList<Student> studentSwap, String targetName, String newName, int q1, int q2, int q3, int q4, int q5)
	{
		for (Student newStudent : studentSwap)
		{
			if (newStudent.getName() == targetName)
			{
				newStudent.setName(newName);
				newStudent.setQuiz1(q1);
				newStudent.setQuiz2(q2);
				newStudent.setQuiz3(q3);
				newStudent.setQuiz4(q4);
				newStudent.setQuiz5(q5);
			}
		}
	}

	//method to insert before a target student
	public static void insertStudent(ArrayList<Student> studentAdd, String targetName, String newStudent, int q1, int q2, int q3, int q4, int q5)
	{
		int position = 0;
		
	    //find location of student you want to insert before
	    for(int i = 0; i < studentAdd.size(); i++)
	        if(studentAdd.get(i).getName().equals(targetName))
	            position = i;

	    //insert student into ArrayList
	    studentAdd.add(position, new Student(newStudent, q1, q2, q3, q4, q5));
	}

	//method to delete by searching for a target student
	public static void deleteStudent(ArrayList<Student> studentList, String targetName)
	{
	    int position = 0;
	    int i;

	    //find position of student you want to delete
	    for(i = 0; i < studentList.size(); i++)
	    {
	        if(studentList.get(i).getName().equals(targetName))
	        {
	            position = i;
	            break;
	        }
	    }
	        
	    //delete student from ArrayList
	    if (i != studentList.size())
	        studentList.remove(position);
	 }
}