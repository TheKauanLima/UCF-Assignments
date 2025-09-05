 /**
 * This class defines a Forest object by extending a Terrain.
 *
 * @author Kauan Lima
 * @version 3/24/24
 */

public class Forest extends Terrain
{
	private int numberofTrees;
	
	public Forest (int l, int w, int n)
	{
		super(l, w);
		
		numberofTrees = n;
	}
	
	public int getNumber()
	{
		return numberofTrees;
	}
}
