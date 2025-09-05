/**
 * Kauan Lima
 * Assignment 0: Pizza Store
 * COP 3330
 * 1/18/2025
 */
import java.util.Scanner;

public class PizzaFunctions {
	public static int calculateTotalCost(int numPizzas, int pricePerPizza)
	{
		// return total cost of all pizzas
		return numPizzas * pricePerPizza;
	}
	
	public static int applyBulkDiscount(int numPizzas, int pricePerPizza, int discountThreshold)
	{
		// check if the number of pizzas is eligible for discount
		if (numPizzas > discountThreshold)
		{
			// discount final result by 10%
			return (int)(calculateTotalCost(numPizzas, pricePerPizza) * 0.9);
		}
		
		// return normal total
		return calculateTotalCost(numPizzas, pricePerPizza);
	}
	
	public static int calculateRewardPoints(int numPizzas)
	{
		// initialize scanner and sum
		Scanner scanner = new Scanner(System.in);
		int sum = 0;
		
		// loop for each reward pizza
		for (int i = 1; i <= numPizzas; i++)
		{
			// prompt for the rewards of each pizza and add to total
			System.out.println("How many rewards for pizza #" + i + ": ");
			sum += scanner.nextInt();
		}
		
		// return total rewards
		return sum;
	}
}
