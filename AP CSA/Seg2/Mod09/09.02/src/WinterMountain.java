 /**
 * This class defines a Winter Mountain object by extending a Mountain.
 *
 * @author Kauan Lima
 * @version 3/24/24
 */

public class WinterMountain extends Mountain
{
	private double temperature;
	
	public WinterMountain (int l, int w, int n, double t)
	{
		super(l, w, n);
		
		temperature = t;
	}
	
	public double getTemperature()
	{
		return temperature;
	}
}
