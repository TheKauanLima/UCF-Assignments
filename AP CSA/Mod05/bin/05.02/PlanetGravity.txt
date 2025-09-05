/**
 * Purpose: Given information of any planet (name, mass, diameter), calculate the surface gravity of
 * 			that planet using Newton's equation of gravity.
 * 
 * @author Kauan Lima
 * @version 11/13/2023
 *
 */

public class PlanetGravity
{
	//start the program
	public static void main(String[] args)
	{
		//print out the header
		title();
		
		//obtain information
		//select the planet's name
		String planetName = "Venus";
		
		//the gravitational constant (G)
		double gravitationalConstant = 6.67 * Math.pow(10, -11);
		
		//enter the mass of the planet
		double massBase = 4.869;
		int massPower = 23;
		double kgPlanetMass = massBase * Math.pow(10, massPower);
		
		//enter the diameter of the planet
		double kmPlanetDiameter = 12103.6;
		double mPlanetDiameter = kmPlanetDiameter * 1000;
		
		//compute information and display it
		//calculate the surface gravity of a given planet
		double planetSurfaceGravity = calculations(gravitationalConstant, kgPlanetMass, mPlanetDiameter);
		
		//print all relevant information
		displayData(planetName, massBase, massPower, kmPlanetDiameter, planetSurfaceGravity);
	}

	//print the header
	public static void title()
	{
		System.out.println("\t\t\tPlanetary Data");
		System.out.println("Planet\t\tDiameter (km)\t\tMass (kg)\tg (m/s^2)");
		System.out.println("-----------------------------------------------------------------");
	}

	//calculate the surface gravity
	public static double calculations(double G, double M, double d)
	{
		return G*M/(Math.pow(d/2, 2) * 1/10);
	}

	//display final information
	public static void displayData(String name, double mass, int power, double d, double gPlanet)
	{
		String M = mass + "E+" + power;
		System.out.println(name + "\t\t" + d + "\t\t" + M + "\t" + gPlanet);
	}
}