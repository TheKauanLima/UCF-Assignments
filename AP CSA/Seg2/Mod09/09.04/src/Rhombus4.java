
/**
 * This class defines a Rhombus object by extending
 * Square.
 * The toString method has been added.
 *
 *
 * @author Kauan Lima
 * @version 3/29/2024
 */
public class Rhombus4 extends Square4
{
    // Constructor for objects of class Rectangle
    public Rhombus4(int l, int w)
    {
    	// call superclass
    	super(l,  w);
    }

    // String to display when object is printed.
    
    public String toString()
    {
        return "Rhombus - " + getLength() + " X " + getWidth();
    }
    
}
