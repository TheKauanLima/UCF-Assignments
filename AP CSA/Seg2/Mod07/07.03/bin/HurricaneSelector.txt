/**
 * @purpose: Print Hurricane data from different years onto the console
 * @author Kauan Lima
 * @version 2/17/2024
 */
 
import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

import javax.imageio.plugins.tiff.ExifGPSTagSet;
public class HurricaneSelector

{

    public static void main(String[] args) throws IOException
    {
        //read data from text file & put in an array
        File fileName = new File("HurricaneData.txt");
        Scanner inFile = new Scanner(fileName);
        int numValues = 0;
        
        //count number of lines in text file
        while (inFile.hasNextLine() )
        {
            inFile.nextLine();
            numValues++;
        }
        inFile.close();
        
        
        //initialize arrays based on lines counted in text file
        int [] years = new int[numValues];
        String [] months = new String[numValues];
        int [] pressures = new int[numValues];
        double [] windSpeeds = new double[numValues];
        String [] names = new String[numValues];
        
        //read and assign data from text file to the arrays
        inFile = new Scanner(fileName);
        int index = 0;
        while(inFile.hasNext() )
        {
            years[index] = inFile.nextInt();
            months[index] = inFile.next();
            pressures[index] = inFile.nextInt();
            windSpeeds[index] = inFile.nextDouble();
            names[index] = inFile.next();
            index++;
        }
        inFile.close();
        
        //convert the windspeed, determine categories
        //create new array for category info
        int[] categories = new int[numValues];
        
        inFile = new Scanner(fileName);
        
        //loop for converting windspeed and category information
        for (index = 0; index < numValues; index++)
        {
        	windSpeeds[index] = windSpeeds[index] * 1.15078;
        	
        	if (windSpeeds[index] < 96)			categories[index] = 1;
        	else if (windSpeeds[index] < 111)	categories[index] = 2;
        	else if (windSpeeds[index] < 130)	categories[index] = 3;
        	else if (windSpeeds[index] < 157)	categories[index] = 4;
        	else								categories[index] = 5;
        }
        inFile.close();
        
        //create a Hurricane ArrayList using the data above
        ArrayList<Hurricane> hurricanes = new ArrayList<Hurricane>();
        
        for (index = 0; index < numValues; index++)
        {
        	hurricanes.add(new Hurricane(years[index], names[index], months[index], categories[index], pressures[index], windSpeeds[index]));
        }
        
        //user prompted for lower bound of years
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the first year of hurricane activity (lowest - 1995): ");
        int firstYear = in.nextInt();
        
        //check if the value is acceptable
        if (firstYear < 1995)
        {
        	System.out.println("Error: year is too low");
        	System.exit(0);
        }
        else if (firstYear > 2019)
        {
        	System.out.println("Error: year is too high");
        	System.exit(0);
        }
        
        //user prompted for upper bound of years
        System.out.print("Enter the last year of hurricane activity (highest - 2019): ");
        int lastYear = in.nextInt();
        System.out.println("\n\n");
        
        in.close();
        
        //check if the value is acceptable
        if (firstYear > lastYear)
        {
        	System.out.println("Error: lower bound cannot be higher than the higher bound");
        	System.exit(0);
        }
        if (lastYear < 1995)
        {
        	System.out.println("Error: year is too low");
        	System.exit(0);
        }
        else if (lastYear > 2019)
        {
        	System.out.println("Error: year is too high");
        	System.exit(0);
        }
        
        
        //print the data
        //use iterations for calculating the average value
        int iterations = 0;
        
        //create min variables
        double minWindSpeed = Integer.MAX_VALUE;
        int minPressure = Integer.MAX_VALUE;
        int minCategory = Integer.MAX_VALUE;
        
        //create max variables
        double maxWindSpeed = Integer.MIN_VALUE;
        int maxPressure = Integer.MIN_VALUE;
        int maxCategory = Integer.MIN_VALUE;
        
        //create sum variables
        double windSpeedSum = 0;
        int categorySum = 0;
        int pressureSum = 0;
        
        //create category counter variables
        int cat1Count = 0;
        int cat2Count = 0;
        int cat3Count = 0;
        int cat4Count = 0;
        int cat5Count = 0;
        
        //print header
        System.out.println("\t\t\tHurricanes " + firstYear + " - " + lastYear + "\n");
        System.out.println("Year\t Hurricane\t Category\t Pressure (mb)\t Wind Speed (mph)");
        System.out.println("=========================================================================");
        
        //loop for printing and calculating values
        for (Hurricane newStorm : hurricanes)
        {
        	//only print and calculate information within the year range
        	if ((newStorm.getYear() >= firstYear) && (newStorm.getYear() <= lastYear))
        	{
        		//print year, name, category, pressure, and wind speed values
        		System.out.println(newStorm);
        		
        		//sum the values printed
        		windSpeedSum += (newStorm.getWindspeed());
        		pressureSum += (newStorm.getPressure());
        		categorySum += (newStorm.getCat());
        		iterations++;
        		
        		//check for min and max values
        		if (newStorm.getWindspeed() < minWindSpeed) minWindSpeed = newStorm.getWindspeed();
        		if (newStorm.getWindspeed() > maxWindSpeed) maxWindSpeed = newStorm.getWindspeed();
        		
        		if (newStorm.getPressure() < minPressure) minPressure = newStorm.getPressure();
        		if (newStorm.getPressure() > maxPressure) maxPressure = newStorm.getPressure();
        		
        		if (newStorm.getCat() < minCategory) minCategory = newStorm.getCat();
        		if (newStorm.getCat() > maxCategory) maxCategory = newStorm.getCat();
        		
        		//check for instances of each category of hurricane
        		if (newStorm.getCat() == 1) cat1Count++;
            	else if (newStorm.getCat() == 2) cat2Count++;
            	else if (newStorm.getCat() == 3) cat3Count++;
            	else if (newStorm.getCat() == 4) cat4Count++;
            	else cat5Count++;
        	}
        }
        
        //prrint footer
        System.out.println("=========================================================================");
        
        //calculate average values
        double catAverage = (double)categorySum / iterations;
        double pressureAverage = (double)pressureSum / iterations;
        double windSpeedAverage = windSpeedSum / iterations;
        
        //print average, min, and max values
        System.out.printf("\tAverage:\t    %-13.1f %-15.1f %.2f%n", catAverage, pressureAverage, windSpeedAverage);
        System.out.printf("\tMinimum:\t    %-13d %-15d %.2f%n", minCategory, minPressure, minWindSpeed);
        System.out.printf("\tMaximum:\t    %-13d %-15d %.2f%n%n", maxCategory, maxPressure, maxWindSpeed);
        
        //print number of categories for each severity
        System.out.println("Summary of Categories:");
        System.out.println("  Cat 1: " + cat1Count);
        System.out.println("  Cat 2: " + cat2Count);
        System.out.println("  Cat 3: " + cat3Count);
        System.out.println("  Cat 4: " + cat4Count);
        System.out.println("  Cat 5: " + cat5Count);
     }
}