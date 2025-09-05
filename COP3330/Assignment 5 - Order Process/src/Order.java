/**
 * Kauan Lima
 * Assignment 5: Order Process
 * COP 3330
 * 3/16/2025
 */
public class Order
{
	// private instance variables
	private int orderNumber;
	private String orderName;
	private int orderTimeToPrepare;
	private static int createdOrders = 0;
	
	// constructor
	public Order (String name, int completeTime)
	{
		createdOrders++;
		orderNumber = createdOrders;
		orderName = name;
		orderTimeToPrepare = completeTime;
	}
	
	// instance methods
	// placeholder method for other getString() in children
	public String getString()
	{
		return "ORDER";
	}
	
	// return order number
	public int getOrder()
	{
		return orderNumber;
	}
	
	// return prepare time
	public int getTime()
	{
		return orderTimeToPrepare;
	}
	
	// return name
	public String getName()
	{
		return orderName;
	}
}
