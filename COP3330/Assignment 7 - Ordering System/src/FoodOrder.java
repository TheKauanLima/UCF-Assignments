/**
 * Kauan Lima
 * Assignment 7: Ordering System
 * COP 3330
 * 4/13/2025
 */
public abstract class FoodOrder implements Comparable<FoodOrder> {
	// private instance variables
	private String customerName;
	private String item;
	private int priority;
	
	// constructor
	public FoodOrder(String customerName, String item, int priority) {
		this.customerName = customerName;
		this.item = item;
		this.priority = priority;
	}
	
	// abstract method
	public abstract void prepareOrder();
	
	// getters
	public String getName() {
		return customerName;
	}
	
	public String getItem() {
		return item;
	}
	
	public int getPriority() {
		return priority;
	}
}
