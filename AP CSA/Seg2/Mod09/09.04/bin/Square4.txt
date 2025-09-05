
/**
 * This class defines a Square object by extending
 * Rectangle.
 * The toString method has been added.
 *
 *
 * @author Kauan Lima
 * @version 3/29/2024
 */
public class Square4 extends Rectangle4
{
    // Constructor for objects of class Rectangle
    public Square4(int l, int w)
    {
    	// call superclass
    	super(l,  w);
    }

    // String to display when object is printed.
    
    public String toString()
    {
        return "Square - " + getLength() + " X " + getWidth();
    }
    
}
