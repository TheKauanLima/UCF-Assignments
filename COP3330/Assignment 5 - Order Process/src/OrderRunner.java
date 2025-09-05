/**
 * Kauan Lima
 * Assignment 5: Order Process
 * COP 3330
 * 3/16/2025
 */
// all imports
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

// runner
public class OrderRunner
{
	private static int currentTime;
	
	// main
	public static void main(String[] args) 
	{
		// create new stack
		Stack<Order> orders = new Stack<Order>();
		
		// scan input file name
		Scanner scanFile = new Scanner(System.in);
		System.out.print("Write input file name (input.txt): ");
		String input = scanFile.next();
		scanFile.close();
		
		// add all orders in input file to stack and print to output.txt
		try
		{
			// scan file
			Scanner scanInput = new Scanner(new File(input));
			int numOrders = scanInput.nextInt();
			
			// create new file
			PrintWriter pw = new PrintWriter("output.txt");
			
			// loop for each order
			for (int i = 0; i < numOrders; i++)
			{
				// get time, initialize current time for first iteration
				int time = scanInput.nextInt();
				if (i == 0) currentTime = time;
				
				// write a new line if the currentTime is less
				// than the next customer's sign in time
				if (currentTime < time && !orders.empty())
					write(orders, pw);
				
				// get other information
				String name = scanInput.next();
				String orderType = scanInput.next();
				int prepareTime = scanInput.nextInt();
				
				// create new order and add to stack
				if (orderType.compareTo("dinein") == 0) {
					DineIn dinein = new DineIn(name, prepareTime);
					orders.add(dinein);
				}
				else if (orderType.compareTo("togo") == 0) {
					ToGo togo = new ToGo(name, prepareTime);
					orders.add(togo);
				}
			}
			
			// empty the remaining contents of the stack
			while (!orders.empty())
				write(orders, pw);
			
			// close scanner and printwriter
			scanInput.close();
			pw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	// write to new file
	public static void write(Stack<Order> orders, PrintWriter pw) {
		currentTime += orders.peek().getTime();
		pw.println(orders.pop().getString() + " " + currentTime + " min");
	}
}
