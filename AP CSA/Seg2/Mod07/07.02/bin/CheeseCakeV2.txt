/**
 * @purpose Calculate several quantities of ingredients with a formula and print onto console with the CheeseCakeTesterV1 class
 *
 * @author  Kauan Lima
 * @version 3/3/2024
 *
 */
public class CheeseCakeV2
{
    private int myQuantity, myServings, myCreamCheese, myVanilla;
    private double mySugar;
    private String myFlavor;
    
   /**
    * Constructor for objects of type CheeseCakeV1
    * @param flavor
    * @param quantity
    */
    CheeseCakeV2(String flavor,int quantity)
    {
        //******* fill in code for constructor here ****//
    	myFlavor = flavor;
    	myQuantity = quantity;
    	
    	mySugar = 0.0;
    	myServings = 0;
    	myCreamCheese = 0;
    	myVanilla = 0;
    }

    /**
     * Mutator method to calculate the number of servings
     */
    
    public void setServings(int servings)
    {
        myServings = servings;
    }
    
    public void calcTotalServings()
    {
        //******* fill in code for method here - 16 servings per cake ****//
    	int totalServings = myQuantity*16;
    	setServings(totalServings);
    }

    /**
     * Mutator method to calculate the Cream Cheese Needed
     */
     
    public void setCreamCheese(int creamCheese)
    {
        myCreamCheese = creamCheese;
    }
    
    public void calcCreamCheese()
    {
        //******* fill in rest of method here - 32 ounces per cake ****//
    	int totalCreamCheese = myQuantity*32;
    	setCreamCheese(totalCreamCheese);
    }
    
    /**
     * Mutator method to calculate the Vanilla Needed
     */
    
    public void setVanilla(int vanilla)
    {
        myVanilla = vanilla;
    }
    
    public void calcVanilla()
    {
        //******* fill in rest of method here - 1 teaspoon per cake ****//
    	int totalVanilla = myQuantity;
    	setVanilla(totalVanilla);
    }

    /**
     * Mutator method to calculate the Sugar Needed
     */
    
    public void setSugar(double sugar)
    {
        mySugar = sugar;
    }
    
    public void calcSugar()
    {
        //******* fill in rest of method here - 1/3 cup per cake ****//
    	double totalSugar = myQuantity*(1/3.0);
    	setSugar(totalSugar);
    }    

    /**
     * Getter method to return the number of cakes (no parameters)
     */
    public int getquantity()
    {
        return myQuantity;
    }

    /**
     * Getter method to return flavor of the cake (no parameters)
     */
    public String getFlavor()
    {
        return myFlavor;
    }

    /**
     * Getter method to return amount of Sugar needed (no parameters)
     */
    public double getSugar()
    {
        return mySugar;
    }

    /**
     * Getter method to return amount of Cream Cheese needed (no parameters)
     */
    public int getCreamCheese()
    {
        return myCreamCheese;
    }

    /**
     * Getter method to return amount of Vanilla needed (no parameters)
     */
    public int getVanilla()
    {
        return myVanilla;
    }

    /**
     * Getter method to return number of Servings (no parameters)
     */
    public int getServings()
    {
        return myServings;
    }
    
    public String toString()
    {
        //******* Practice your printf() skills by formatting this data! ****//
        return String.format("%4d     | %-13s | %6d oz    | %5d    | %4.2f cups | %3d tsps  |", getquantity(), getFlavor(), getCreamCheese(), getServings(), getSugar(), getVanilla());
    }
}