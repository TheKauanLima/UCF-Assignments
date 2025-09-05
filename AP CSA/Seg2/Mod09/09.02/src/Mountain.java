 /**
 * This class defines a Mountain object by extending a Terrain.
 *
 * @author Kauan Lima
 * @version 3/24/24
 */

public class Mountain extends Terrain
{
	private int numberOfMountains;
	
	public Mountain (int l, int w, int n)
	{
		super(l, w);
		
		numberOfMountains = n;
	}
	
	public int getNumber()
	{
		return numberOfMountains;
	}
}
