/**
 * Prompt for personal information and tickets to watch a movie
 * 
 * @author Kauan Lima
 * @version 7/23/23
 */
import java.util.Scanner;

public class BuyMovieTicketsV2
{
	public static void main(String[] args)
	{
		// prompt for all necessary information
		// add the Scanner object
		Scanner in = new Scanner(System.in);
		
		// welcome the user
		System.out.println("Good Evening.");
		
		// prompt for first and last name
		System.out.print("Please enter your first and last name: ");
		String firstName = in.next();
		String lastName = in.nextLine();
		
		// prompt for the date
		System.out.print("Enter today's date (mm/dd/yyyy): ");
		String currentDate = in.next();
		
		// scanner skips this
		in.nextLine();
		
		// prompt for the movie to see
		System.out.print("What movie would you like to see? ");
		String movie = in.nextLine();
		
		// prompt for the number of tickets
		System.out.print("How many tickets? ");
		String numberOfTickets = in.next();
		
		// prompt for the ticket price
		System.out.print("What is the ticket price? (Please enter a dollar sign in front) ");
		String ticketPrice = in.next();
		
		// prompt for debit card number
		System.out.print("Enter your debit card number (#####-###-####): ");
		String debitCardNumber = in.next();
		
		// prompt for PIN
		System.out.print("Enter your PIN (####): ");
		String PIN = in.next();
		System.out.println();
		
		// separate the rest of the program
		System.out.println("*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*");
		System.out.println("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
		
		// e-receipt container
		// print e-receipt and date
		System.out.println("Your e-receipt\n");
		System.out.println(currentDate.replaceAll("/", "-"));
		
		// print order number
		System.out.println("Order number: " + lastName.substring(2, 4) + debitCardNumber.substring(6, 9) + "\n");
		
		// print user information
		// print first initial and last name
		System.out.println(firstName.substring(0, 1) + ". \t" + lastName);
		
		// hide debit information
		System.out.println("Account: #####-###-" + debitCardNumber.substring(10));
		
		// display movie
		System.out.println("Movie: " + movie);
		
		// display number of tickets
		System.out.println("Number of Tickets: " + numberOfTickets);
		
		// display ticket price
		System.out.println("Ticket Price: " + ticketPrice.substring(1));
		System.out.println();
		
		// display the amount charged
		String ticketPriceValue = ticketPrice.substring(1);
		double doubleTicketPrice = Double.parseDouble(ticketPriceValue);
		int intNumberOfTickets = Integer.parseInt(numberOfTickets);
		
		double amountCharged = doubleTicketPrice * intNumberOfTickets;
		
		System.out.printf("$%.1f will be debited to your account.\n\n", amountCharged);
		System.out.println("Thank you. Enjoy your movie tonight.");
		System.out.println("*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*");
		System.out.println("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
	}
}
