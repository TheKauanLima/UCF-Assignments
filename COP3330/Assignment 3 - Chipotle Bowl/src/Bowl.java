/**
 * Kauan Lima
 * Assignment 3: Chipotle Bowl
 * COP 3330
 * 2/18/2025
 */
import java.util.LinkedList;
import java.util.Scanner;

public class Bowl {
	
	// private instance variable(s)
	private LinkedList<String> strList;
	
	// initialize linked list and add element
	public Bowl(String ingredient) {
		strList = new LinkedList<>();
		strList.add(ingredient);
	}
	
	// initialize linked list
	public Bowl() {
		strList = new LinkedList<>();
	}
	
	public void addOne(String addThis) {
		// add a single element
		strList.add(addThis);
	}
	
	public void AddManyMixed(LinkedList<String> ingredientsList) {
		// set index variables
	    int i = 1;
	    int ingIndex = 0;

	    while (ingIndex < ingredientsList.size()) {
	    	// if i is greater than strList.size()
	        if (i >= strList.size()) {
	        	// add each ingredient in ingredientsList sequentially
	            for (int j = ingIndex; j < ingredientsList.size(); j++)
	                strList.add(ingredientsList.get(j));
	            ingredientsList.clear();
	            break;
	        }
	        // if i is less than strList.size(), add it to
	        // strList and pop to remove element from linked list.
	        // increase i by 2 to add to appropriate spot next time.
	        else {
	            strList.add(i, ingredientsList.get(0));
	            ingredientsList.pop();
	            i += 2;
	        }
	    }
	}
	
	public double calcCost() {
		// calculate cost, starts at 10 and adds .10 for each letter in each ingredient
		double price = 10;
		
		for (String ingredient : strList)
			price += (ingredient.length() * .10 );
		
		return price;
	}
	
	public void printIngredients() {
		// print each index in strList and its value
	    for (int i = 0; i < strList.size(); i++)
	        System.out.println((i + 1) + ": " + strList.get(i));
	}

	public static void main(String[] args) {
		// set local variables and objects
		Bowl bowl;
		Scanner in = new Scanner(System.in);
		LinkedList<String> ingList = new LinkedList<>();
		
		// prompt user for ingredients
		System.out.print("Start with an ingredient? (yes/no): ");
		String option = in.next();
		
		// check for y/n answer
		if (option.charAt(0) == 'y') {
			// enter first ingredient in new bowl
			System.out.print("Enter your first ingredient: ");
			String first = in.next();
			
			bowl = new Bowl(first);
		} else
			// initialize new bowl
			bowl = new Bowl();
		
		// prompt for another ingredient and add
		System.out.print("Enter another ingredient: ");
		String otherIng = in.next();
		bowl.addOne(otherIng);
		
		// set up loop for adding more ingredients
		int i = 0;
		int iter = 2;
		System.out.println("Enter ingredients (type 'done' to finish):");
		while (i < iter) {
			// obtain new ingredient
			String newIng = in.next();
			
			// check if user is done
			if (newIng.compareToIgnoreCase("done") == 0) {
				// if second iteration, add ingredients mixed into bowl
				if (i == 1)
					bowl.AddManyMixed(ingList);
				
				// print bowl information
				System.out.println("Your Chipotle Bowl contains:");
				bowl.printIngredients();
				
				System.out.printf("Total Cost: $%.2f%n", bowl.calcCost());
				
				// increase iteration
				i++;
				if (i != iter)
					// signal the start of the second iteration
					System.out.println("Enter ingredients (type 'done' to finish):");
				continue;
			}
			
			// if user not done, continue to add ingredients
			if (newIng.compareToIgnoreCase("done") != 0) {
				if (i != 1)
					bowl.addOne(newIng);
				// if second iteration, add ingredients to a linked list
				else
					ingList.add(newIng);
			}
		}
		// close scanner
		in.close();
	}
}
