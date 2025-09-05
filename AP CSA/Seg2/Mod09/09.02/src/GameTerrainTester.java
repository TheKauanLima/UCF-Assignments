 /**
 * This tests the Terrain class hierarchy.
 *
 * @author Kauan Lima
 * @version 3/24/24
 */

public class GameTerrainTester
{
    public static void main(String []args)
    {

        Terrain plane =  new Terrain(2, 4);
        Mountain range = new Mountain(6, 8, 10);
        Forest canopy =  new Forest(5, 7, 9);
        Desert  barren = new Desert(7, 9, 11);
        WinterMountain frigidRange =  new WinterMountain(12, 14, 16, 17.13);
        Wetland marsh =  new Wetland(13, 15, 17, 18);

        // Terrain
        System.out.println(plane.getTerrainSize());
        System.out.println();

        // Forest
        System.out.println("Forest " + canopy.getTerrainSize()
        						+ " and has " + canopy.getNumber() + " trees");
        System.out.println();

        // Mountain
        System.out.println("Mountain " + range.getTerrainSize()
        						+ " and has " + range.getNumber() + " mountains");
        System.out.println();

        // Winter Mountain
        System.out.println("Winter Mountain " + frigidRange.getTerrainSize()
        						+ " and has " + frigidRange.getNumber() + " mountains and temperature "
        						+ frigidRange.getTemperature() + " degrees");
        System.out.println();
        
        // Desert
        System.out.println("Desert " + barren.getTerrainSize()
        						+ " and has " + barren.getNumber() + " dunes");
        System.out.println();
        
        // Wet lands
        System.out.println("Wet " + marsh.getTerrainSize()
        						+ " and has " + marsh.getNumber() + " trees and "
        						+ marsh.getNumberLakes() + " lakes");
        System.out.println();
    }
}
