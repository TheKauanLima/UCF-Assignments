
/**
 * This class demonstrates classes that override
 * the toString method.
 *
 * @author Kauan Lima
 * @version 3/29/2024
 */
import java.util.*;
public class ShapesTester4
{
    public static void main(String []args)
    {
        Rectangle4 one = new Rectangle4(12, 20);
        Box4 two = new Box4(4, 4, 4);
        Box4 three = new Box4(4, 12, 8);
        Cube4 four = new Cube4(4, 4, 4);
        Square4 five = new Square4(12, 20);
        Rhombus4 six = new Rhombus4(5, 7);

        //Print all shapes
        ArrayList<Rectangle4> shapes = new ArrayList<Rectangle4>();

        System.out.println("My shapes: \n");
        
        shapes.add( one );
        shapes.add( two );
        shapes.add( three );
        shapes.add( four );
        shapes.add( five );
        shapes.add( six );

        for(Rectangle4 rect: shapes)
        {
        	//System.out.print(rect);
        	showEffectBoth(rect);
            System.out.println();
        }
        
        System.out.println("\nTest for equality:\n");
        
        //Equality check
        if(two.equals(four))
        {
        	showEffectBoth(two);
        	System.out.print(" IS same size as ");
        	showEffectBoth(four);
        	System.out.println();
        }
        else
        {
        	showEffectBoth(two);
        	System.out.print(" is NOT same size as ");
        	showEffectBoth(four);
        	System.out.println();
		}
        
        System.out.println();
        
        if(four.equals(three))
        {
        	showEffectBoth(three);
        	System.out.print(" IS same size as ");
        	showEffectBoth(four);
        	System.out.println();
        }
        else
        {
        	showEffectBoth(three);
        	System.out.print(" is NOT same size as ");
        	showEffectBoth(four);
        	System.out.println();
		}
        
    }

    public static void showEffectBoth(Rectangle4 r)
    {
        System.out.print(r);
    }

}
