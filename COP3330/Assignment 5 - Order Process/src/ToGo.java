/**
 * Kauan Lima
 * Assignment 5: Order Process
 * COP 3330
 * 3/16/2025
 */
public class ToGo extends Order
{
	// constructor
	public ToGo(String name, int completeTime)
	{
		super(name, completeTime);
	}
	
	// return string for fulfilled to go order
	public String getString()
	{
		return "Order #" + super.getOrder() + " (To Go): " + super.getName();
	}
	
	// return the time needed to prepare a to go order
	public int getTime()
	{
		return super.getTime() + 5;
	}
}
