/**
 * Kauan Lima
 * Assignment 5: Order Process
 * COP 3330
 * 3/16/2025
 */
public class DineIn extends Order
{
	// constructor
	public DineIn(String name, int completeTime)
	{
		super(name, completeTime);
	}
	
	// return string for fulfilled dine in order
	public String getString()
	{
		return "Order #" + super.getOrder() + " (Dine In): " + super.getName();
	}
}
