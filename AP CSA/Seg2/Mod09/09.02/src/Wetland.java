 /**
 * This class defines a Wetland object by extending a Forest.
 *
 * @author Kauan Lima
 * @version 3/24/24
 */

public class Wetland extends Forest
{
	private int numberofLakes;
	
	public Wetland (int l, int w, int nT, int nL)
	{
		super(l, w, nT);
		
		numberofLakes = nL;
	}
	
	public int getNumberLakes()
	{
		return numberofLakes;
	}
}
