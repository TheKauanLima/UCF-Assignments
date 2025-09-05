/**
 * @purpose Gain information on several cheesecake orders and print out the ingredients of the cheesecake using the CheesCakeV1 method
 *
 * @author Kauan Lima
 * @version 3/3/2024
 *
 */
import java.util.ArrayList;

public class CheeseCakeTesterV2
{
    public static void main(String[] args)
    {
    	//initialize information for arrayList
    	String flavor1 = "Blueberry";
    	String flavor2 = "Strawberry";
    	String flavor3 = "Cherry";
    	String flavor4 = "Jalapeno";
    	String flavor5 = "Dill Pickle";
    	String flavor6 = "Fig";
    	
    	int quantity1 = 5;
    	int quantity2 = 6;
    	int quantity3 = 4;
    	int quantity4 = 1;
    	int quantity5 = 2;
    	int quantity6 = 3;
    	
        //initializing and declareing an ArrayList and adding in objects as elements
        ArrayList<CheeseCakeV2> cake = new ArrayList<CheeseCakeV2>();
        
        // add CheeseCake to the ArrayList
        cake.add(new CheeseCakeV2(flavor1, quantity1));
        cake.add(new CheeseCakeV2(flavor2, quantity2));
        cake.add(new CheeseCakeV2(flavor3, quantity3));
        cake.add(new CheeseCakeV2(flavor4, quantity4));
        cake.add(new CheeseCakeV2(flavor5, quantity5));
        cake.add(new CheeseCakeV2(flavor6, quantity6));
        
        //calls several method for each object to perform calculations
        for(CheeseCakeV2 dataRecord : cake)
        {
            // invoke methods
        	dataRecord.calcCreamCheese();
        	dataRecord.calcTotalServings();
        	dataRecord.calcSugar();
        	dataRecord.calcVanilla();
        }
        
        //printing the format of the table
        System.out.println(" |       Cheese Cake Data           |             Ingredient Calculations             |");
        System.out.println(" | Index | Quantity |  Flavor       | Cream Cheese | Servings |   Sugar   |  Vanilla  |");
        System.out.println(" |-------|----------|---------------|--------------|----------|-----------|-----------|");

        
        //using a for loop to print out the objects' data`
        for(int index = 0; index < cake.size(); index ++)
        {
            // print each CheeseCake's data
        	System.out.println(" |   " + index + "   | " + cake.get(index));
        }
    }
}
