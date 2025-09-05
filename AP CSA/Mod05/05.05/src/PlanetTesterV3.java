/**
 * @purpose: PlanetTesterV3 client class 
 *
 * @author APCS Team
 * @version FLVS 2020
 */
 
 
public class PlanetTesterV3
{

   public static void printPlanet(String n, double rad)
   {
       System.out.println("Planet " + n + " has a radius of " + rad);
   }
   

   public static void main (String[] args) {
   
       String name1 = "Jupiter";
       int diam1 = 142984;
       double radius1 = 0.0;
       
       planetv3 planet1 = new planetv3();
       
       radius1 = planet1.calcRadius(diam1);
       printPlanet(name1, radius1);
       
       String name = "Mars";
       int diam = 6794;
       double radius = 0.0;
       
       planetv3 planet2 = new planetv3();
       
       radius = planet2.calcRadius(diam);
       printPlanet(name, radius);
   
   }
    
    
}

