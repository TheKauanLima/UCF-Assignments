/**
 * Kauan Lima
 * Assignment 1: Knightro's Pizza
 * COP 3330
 * 4/13/2025
 */
public class Pizza
{
	// private instance variables
	private double size;
	private int slices;
	
	// constructor
	public Pizza(double pizzaSize) {
		size = pizzaSize;
		slices = 1;
	}
	
	// update slices variable
	public void setSlices(int slices) {
		if (slices > this.slices) {
			this.slices = slices;
			System.out.println("We cut the pizza");
		} else
			System.out.println("It is already cut in smaller pieces");
	}
	
	// calculate and return the area of each slice
	public double areaPerSlice() {
		double sliceArea = (Math.PI * Math.pow((size / 2), 2)) / slices;
		return sliceArea;
	}
	
	// print each slice
	public void displaySlices() {
		for (int i = 0; i < slices; i++)
			System.out.println("Slice " + (i + 1) + " is delicious!");
	}
	
	// describe the variables set for the pizza
	public String describePizza() {
		String descriptionString = "Size: " + size + ", Slices: " + slices;
		return descriptionString;
	}
}
