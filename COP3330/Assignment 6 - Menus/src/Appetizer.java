/**
 * Kauan Lima
 * Assignment 6: Menus
 * COP 3330
 * 3/30/2025
 */
public class Appetizer implements MenuItem {
	// private instance variables
	private String name;
	private double price;
	
	// constructor
	public Appetizer(String name, double price) {
		this.name = name;
		this.price = price;
	}
	
	// get methods
	public String getName() {
		return name;
	}
	
	public double getPrice() {
		return price;
	}
	
	public String getType() {
		return "Appetizer";
	}
	
	// return the correct order, appetizer > main course > dessert. Alphabetical in each rank.
	public int compareTo(MenuItem other) {
	    int thisTypeRank = getTypeRank(this.getType());
	    int otherTypeRank = getTypeRank(other.getType());

	    // return first element in alphabetical order if ranks are equal
	    if (thisTypeRank == otherTypeRank)
	        return this.getName().compareTo(other.getName());
	    else
	    	// return lowest rank
	        return Integer.compare(thisTypeRank, otherTypeRank);
	}

	// return priority rank
	private int getTypeRank(String type) {
	    switch (type) {
	        case "Appetizer":
	            return 0;
	        case "Main Course":
	            return 1;
	        default:
	            return 2;
	    }
	}
}
