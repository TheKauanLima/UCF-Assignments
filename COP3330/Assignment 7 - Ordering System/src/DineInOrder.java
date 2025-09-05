/**
 * Kauan Lima
 * Assignment 7: Ordering System
 * COP 3330
 * 4/13/2025
 */
public class DineInOrder extends FoodOrder {
	// constructor
	public DineInOrder(String customerName, String item, int priority) {
		super(customerName, item, priority);
	}

	@Override
	// compare the priority correctly (lower priority = closer to head of queue)
	public int compareTo(FoodOrder o) {
		return Integer.compare(super.getPriority(), o.getPriority());
	}

	@Override
	// implement the abstract method
	public void prepareOrder() {
		System.out.printf("Preparing dine-in order for %s: %s\n", getName(), getItem());
	}
	
}
