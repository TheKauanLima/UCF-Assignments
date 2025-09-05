/**
 * @purpose: Create a catapult class to test various values such as speed, angle, and use a 2D array.
 * 
 * @author Kauan Lima
 * @version 3/10/2024
 */
public class Catapult
{
	public Catapult()
	{
	}
	
	public static double calcDistance(int speed, int angle)
	{
		return (Math.pow(speed, 2) * Math.sin(2*Math.toRadians(angle))) / 9.81;
	}
}
