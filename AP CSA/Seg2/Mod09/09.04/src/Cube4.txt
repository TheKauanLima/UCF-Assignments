/**
 * This class defines a Cube object by extending
 * Box.
 * The toString method has been added.
 *
 * @author Kauan Lima
 * @version 3/29/2024
 */
public class Cube4 extends Box4
{
    // instance variables
    private int height;

    // Constructor for objects of class Box
    public Cube4(int l, int w, int h)
    {
        // call superclass
        super(l, w, h);

        // initialize instance variables
        height = h;
    }

    // return the height
    public int getHeight()
    {
        return height;
    }

    // String to display when object is printed.
    
    public String toString()
    {
        return "Cube - " + getLength() + " X " + getWidth() + " X " + height;
    }
    
}
