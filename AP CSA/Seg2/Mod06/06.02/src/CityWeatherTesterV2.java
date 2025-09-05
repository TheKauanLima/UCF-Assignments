/**
 * Purpose: Display weather information through the use of arrays and objects. Information such as fahrenheit or celsius, inches or cm, and months of the year for rain and temperatures.
 * 
 * @author Kauan Lima
 * @version 1/15/2024
 */
import java.util.Scanner;
public class CityWeatherTesterV2
{
    
   
    
    // method to print results (formatting output will be done in 6.02)
    public static void printData(String[] month, double[] temperature, double[] precipitation, String state, String city, String tempLabel, String precipLabel, double avgTemp, double totPrec)
    {
        //Output: display table of weather data including average and total
        System.out.println();
        System.out.println("           Weather Data");
        System.out.println("      Location: " + city +", " + state);
        System.out.println("Month     Temperature (" +  tempLabel + ")     Precipitation (" + precipLabel + ")");
        System.out.println();
        System.out.println("***************************************************");
        for( int index = 0; index < temperature.length; index++)
        {
        	//use printf to format
        	System.out.printf("%5s%15.1f%15.1f", month[index] + ".", temperature[index], precipitation[index]);
        	//System.out.printf("%10s", temperature[index]);
        	System.out.println();
        }
        System.out.println("***************************************************");
        System.out.printf("Average: %1.1f    Total: %1.1f", avgTemp, totPrec);
    }
        
   
    
    public static void main (String [ ] args)
    {

        //Declare and initialize variables
        Scanner in = new Scanner(System.in);  //will be used in 6.02
        String city = "Orlando";  //choose a city from the table provided
        String state = "Florida";  //choose a city from the table provided
  
        String [] month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};     //complete initialization of months array
        double [] temperature ={60.9, 62.6, 67.4, 71.5, 77.1, 81.2, 82.4, 82.5, 81.1, 75.3, 68.8, 63.0};     //complete initialization of temperatures array
        double [] precipitation ={2.4, 2.4, 3.5, 2.4, 3.7, 7.4, 7.2, 6.3, 5.8, 2.7, 2.3, 2.3};     //complete initialization of precipitation array
    
        String tempLabel = "F";    //initialize to F
        String precipLabel = "in."; //initialize to in
        
        //instantiate CityWeatherV1 object 
        CityWeatherV2 orlando = new CityWeatherV2(month, temperature, precipitation);
        
        //input to decide F/C and in/cm
        System.out.println("Choose the temperature scale (F = Fahrenheit, C = Celsius)");
        char temperachar = in.next().charAt(0);
		System.out.println();
		
		System.out.println("Choose the precipitation scale (i = inches, c = centimeters)");
        char precipichartion = in.next().charAt(0);
		System.out.println();
		
        //conditions & method call to convert temp, if needed
		if (temperachar == 'C' || temperachar == 'c')
		{
			tempLabel = "C";
			orlando.FtoC();
		}
		else;
		
        //conditions & method call to convert prec, if needed
		if (precipichartion == 'c')
		{
			precipLabel = "cm";
			orlando.intocm();
		}
		else;
		
        //method call to calculate the average temperature
        double avgTemp = orlando.avgTemp();
        
        //method call to calculate the total precipitation
        double totPrec = orlando.avgPrec();
        
        //method call to print results (hint: Need parameters for month, temperature, precipitation arrays, data labels and the average temperature, total precipitation variables)
        printData(month, temperature, precipitation, state, city, tempLabel, precipLabel, avgTemp, totPrec);

    }//end main
}//end class

