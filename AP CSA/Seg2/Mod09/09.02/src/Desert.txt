 /**
 * This class defines a Desert object by extending a Terrain.
 *
 * @author Kauan Lima
 * @version 3/24/24
 */

public class Desert extends Terrain
{
	private int numberofDunes;
	
	public Desert (int l, int w, int n)
	{
		super(l, w);
		
		numberofDunes = n;
	}
	
	public int getNumber()
	{
		return numberofDunes;
	}
}
