/**
 * This class defines a Box object by extending
 * Rectangle and includes height.
 * The toString method has been added.
 *
 * @author Kauan Lima
 * @version 3/29/2024
 */
public class Box4 extends Rectangle4
{
    // instance variables
    private int height;

    // Constructor for objects of class Box
    public Box4(int l, int w, int h)
    {
        // call superclass
        super(l, w);

        // initialize instance variables
        height = h;
    }

    // return the height
    public int getHeight()
    {
        return height;
    }
    
    // override Object equals
    public boolean equals(Box4 r)
    {
    	if (getLength() == r.getLength() && getWidth() == r.getWidth() && getHeight() == r.getHeight())
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }

    // String to display when object is printed.
    
    public String toString()
    {
        return "Box - " + getLength() + " X " + getWidth() + " X " + height;
    }
    
}
