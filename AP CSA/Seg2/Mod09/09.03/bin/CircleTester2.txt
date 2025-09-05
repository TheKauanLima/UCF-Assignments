import java.util.ArrayList;

/**
 * Test the circle methods
 * 
 * @author Kauan Lima
 * @version 3/28/2024
 */
public class CircleTester2
{
	public static void showCenter(Circle2 c)
	{
		System.out.println(c.getCenter() );
	}
	
	public static void main(String[] args)
	{
		Circle2 circle = new Circle2(2, 4, 6);
		Cylinder2 cylinder = new Cylinder2(10, 8, 6, 4);
		Oval2 oval = new Oval2(5, 3, 1, 3);
		OvalCylinder2 ovalCylinder = new OvalCylinder2(11, 9, 7, 5, 6);
		
		ArrayList<Circle2> circles = new ArrayList<>();
		circles.add(circle);
		circles.add(cylinder);
		circles.add(oval);
		circles.add(ovalCylinder);
		
		for (Circle2 iterate : circles)
		{
			System.out.print("For " + iterate.getName() + " the ");
			showCenter(iterate);
		}
	}
}
