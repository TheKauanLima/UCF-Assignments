/**
 * Kauan Lima
 * Assignment 6: Menus
 * COP 3330
 * 3/30/2025
 */
// interface
public interface MenuItem extends Comparable<MenuItem> {
	public String getName();
	public double getPrice();
	public String getType();
	public int compareTo(MenuItem other);
}
