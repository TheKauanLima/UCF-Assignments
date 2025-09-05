import java.util.Scanner;

public class A0Runner {

	public static void main(String[] args) {
		// Do NOT change anything in this file.
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the number of pizzas ordered: ");
		int pizzas = scan.nextInt();
		System.out.print("Enter the price per pizza: ");
		int price = scan.nextInt();
		System.out.println("Total cost of order: $"+PizzaFunctions.calculateTotalCost(pizzas, price));

		System.out.print("Enter the discount threshold: ");
		int threshold = scan.nextInt();
		System.out.println("Final cost after discount: $" + PizzaFunctions.applyBulkDiscount(pizzas, price, threshold));

		System.out.print("Enter the number of pizzas for rewards: ");
		int rewards = scan.nextInt();
		int total = PizzaFunctions.calculateRewardPoints(rewards);
		System.out.println("Total reward points earned: "+ total); 
	}

}
