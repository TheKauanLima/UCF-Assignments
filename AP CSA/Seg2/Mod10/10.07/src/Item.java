/**
 * @purpose: Create an item class to test
 * 
 * @author Kauan Lima
 * @version 4/14/2024
 */
public class Item
{
	private String name;
	private int number;
	private double price;
	private int quantity;
	
	public Item(String n, int pn, double p, int q)
	{
		name = n;
		number = pn;
		price = p;
		quantity = q;
	}
	
	public String getName()
	{
		return name;
	}
	
	public int getNumber()
	{
		return number;
	}
	
	public double getPrice()
	{
		return price;
	}
	
	public int getQuantity()
	{
		return quantity;
	}
	
	public String toString()
	{
		return String.format("  %13s| %15d| $%13.2f| %17d|", getName(), getNumber(), getPrice(), getQuantity());
	}
}
