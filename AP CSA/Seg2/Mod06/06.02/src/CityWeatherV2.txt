/**
 * Purpose: Create an class capable of an object that stores and calculates weather data.
 * 
 * @author Kauan Lima
 * @version 1/15/2024
 */

public class CityWeatherV2 {
    // private instance variables - three arrays
	private String[] month;
	private double[] temperature;
	private double[] precipitation;
	
    // constructor with parameters
	public CityWeatherV2()
	{
		
	}
	
	public CityWeatherV2(String[] m, double[] t, double[] p)
	{
		month = m;
		temperature = t;
		precipitation = p;
	}
	
    // setters and getters for each private instance variable
	public String[] getMonth()
	{
		return month;
	}
	
	public double[] getTemperature()
	{
		return temperature;
	}
	
	public double[] getPrecipitation()
	{
		return precipitation;
	}
	
	public void setMonth(String[] newMon)
	{
		month = newMon;
	}
	
	public void setTemperature(double[] newTemp)
	{
		temperature = newTemp;
	}
	
	public void setPrecipitation(double[] newPrec)
	{
		precipitation = newPrec;
	}
	
    // method to calculate the average of temperature
    public double avgTemp()
    {
    	double tempSum = 0;
    	for (int i = 0; i < temperature.length; i++)
        {
            tempSum += temperature[i];
        }
    	
    	double avgTemp = tempSum / temperature.length;
    	return avgTemp;
    }
    
    // method to calculate total precipitation array
	public double avgPrec()
	{
		double totPrec = 0;
    	for (int i = 0; i < precipitation.length; i++)
        {
            totPrec += precipitation[i];
        }
    	
    	return totPrec;
	}
 
    // method to calculate temperature in Celsius (current index of temperature array passed as a parameter) - to be completed in 6.02
    public double[] FtoC()
    {
    	for (int i = 0; i < temperature.length; i++)
        {
            temperature[i] = ((temperature[i] - 32) * 5) / 9.0;
            //System.out.println(temperature[i]);
        }
    	
    	return temperature;
    }
    
    // method to calculate precipitation in centimeters (current index of precipitation array passed as a parameter) - to be completed in 6.02
    public double[] intocm()
    {
    	for (int i = 0; i < precipitation.length; i++)
        {
            precipitation[i] = precipitation[i] * 2.54 ;
        }
    	
    	return precipitation;
    }

}
