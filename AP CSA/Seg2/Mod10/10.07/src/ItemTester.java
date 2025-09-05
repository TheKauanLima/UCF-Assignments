/**
 * @purpose:
 * 
 * @author Kauan Lima
 * @version 4/14/2024
 */
public class ItemTester
{
	public static void main(String[] args)
	{
		//create array
		Item[] products = {	new Item("Toothbrush", 457, 3.20, 20),
							new Item("Chips", 5673, 4.99, 15),
							new Item("Computer", 3745, 539.99, 50),
							new Item("Calculator", 4574, 17.99, 25),
							new Item("Sketchbook", 1223, 14.99, 12),
							new Item("T-Shirt", 657, 14.99, 31),
							new Item("Vegetables", 157, 0.99, 100),
							new Item("Bread", 123, 8.50, 40),
							new Item("Makeup", 2344, 11.99, 10),
							new Item("Bleach", 892, 9.99, 19),
							new Item("Flowers", 5671, 15.99, 13) };
		
		//print original array
		System.out.println("<< Original List >>\n");
		traverse(products);
		System.out.println("\n\n");
		
		
		//selection sort by name and print array
		System.out.println("<< Ascending Product Name List >>\n");
		products = selectionSortName(products, 1);
		traverse(products);
		System.out.println("\n\n");
		
		System.out.println("<< Descending Product Name List >>\n");
		products = selectionSortName(products, 0);
		traverse(products);
		System.out.println("\n\n");
				
				
		//selection sort by product ID and print array
		System.out.println("<< Ascending Product Number List >>\n");
		products = selectionSortProductNumber(products, 1);
		traverse(products);
		System.out.println("\n\n");
		
		System.out.println("<< Descending Product Number List >>\n");
		products = selectionSortProductNumber(products, 0);
		traverse(products);
		System.out.println("\n\n");
			
		
		//merge sort by price and print array
		System.out.println("<< Ascending Price List >>\n");
		mergeSortPrice(products, 0, products.length-1);
		traverse(products);
		System.out.println("\n\n");
		
		
		//insertion sort by quantity and print array
		System.out.println("<< Ascending Quantity List >>\n");
		products = insertionSortQuantity(products, 1);
		traverse(products);
		System.out.println("\n\n");
		
		System.out.println("<< Descending Quantity List >>\n");
		products = insertionSortQuantity(products, 0);
		traverse(products);
		System.out.println("\n\n");
	}
	
	//traverse and print each elements of the array
	public static void traverse(Item[] products)
	{
		System.out.println("| Product Name | Product Number | Product Price | Product Quantity |");
		System.out.println("====================================================================");
		
		for (Item items: products)
		{
			System.out.println(items.toString());
		}
	}

	//sort the array with selection sort in ascending or descending order by the name
	public static Item[] selectionSortName(Item[] original, int order)
	{
		//declare necessary variables
	    int i;
	    int j;
	    int posMax;
	    Item temp;

	    //start sort
	    for ( i = original.length - 1 ; i >= 0 ; i-- )
	    {
	        // find largest element in the i elements
	        posMax = 0;
	        for (j = 0 ; j <= i ; j++)
	        {
	            //check for ascending/descending
	            if (order == 1)
	            {
	            	if (original[j].getName().compareTo(original[posMax].getName()) > 0)
	                    posMax = j;
	            }
	            else
	            {
	            	if (original[j].getName().compareTo(original[posMax].getName()) < 0)
	                    posMax = j;
	            }
	        }
	            
	        // swap the item with the largest cost 
	        // with the element in position i
	        // now the item is in its proper location
	        temp = original[i];
	        original[i] = original[posMax];
	        original[posMax] = temp;
	    }
	        
	    return original;
	}
	
	
	//sort the array with selection sort in ascending or descending order by the product number
	public static Item[] selectionSortProductNumber(Item[] original, int order)
    {
		//declare necessary variables
        int i;
        int j;
        int posMax;
        Item temp;

        //start sort
        for ( i = original.length - 1 ; i >= 0 ; i-- )
        {
            // find largest element in the i elements
            posMax = 0;
            for (j = 0 ; j <= i ; j++)
            {
            	//check for ascending/descending
                if (order == 1)
                {
                	if (original[j].getNumber() > original[posMax].getNumber())
                        posMax = j;
                }
                else
                {
                	if (original[j].getNumber() < original[posMax].getNumber())
                        posMax = j;
                }
            }
            
            // swap the item with the largest cost 
            // with the element in position i
            // now the item is in its proper location
            temp = original[i];
            original[i] = original[posMax];
            original[posMax] = temp;
        }
        
        return original;
    }
   
	
	//sort the array with merge sort by price
	public static void mergeSortPrice(Item[] p, int low, int high)
    {
        if( low == high )
            return;

        int mid = ( low + high ) / 2;

        mergeSortPrice( p, low, mid );       // recursive call
        mergeSortPrice( p, mid + 1, high);   // recursive call

        //Debugging Statements 
        //uncomment to print the listings after each pass through the sort
        //System.out.println("\nCurrent list");
        //for(HouseListing h : a)  
        //    if( h != null) System.out.printf("$%10.2f \n", h.getCost() );
                
        merge( p, low, mid, high);
    }
	
	public static void merge( Item[] p, int low, int mid, int high )
    {
        Item[] temp = new Item[ high - low + 1 ];

        int i = low, j = mid + 1, n = 0;

        while( i <= mid || j <= high )
        {
            if( i > mid )
            {
                temp[ n ] = p[ j ];
                j++;
            }
            else if( j > high )
            {
                temp[ n ] = p[ i ];
                i++;
            }
            else if( p[ i ].getPrice() < p[ j ].getPrice() )
            {
                temp[ n ] = p[ i ];
                i++;
            }
            else
            {
                temp[ n ] = p[ j ];
                j++;
            }
            n++;
        }

        for( int k = low ; k <= high ; k++ )
            p[ k ] = temp[ k - low ];
    }

	
	//sort the array with insertion sort in ascending or descending order by the quantity
	public static Item[] insertionSortQuantity(Item[] original, int order)
    {
		//create new array for sorting
        Item[] sort = new Item[original.length];

        //insertion sort loop
        for (int i = 0 ; i < original.length ; i++)
        {
        	//create necessary variables: current array information, current index, previous index
            Item next = original[i];
            int newIndex = 0;
            int j = i;
            
            //start checking from the second element
            while (j > 0 && newIndex == 0)
            {
            	//check for ascending/descending order
                if (order == 1)
                {
                	//order ascending
                	if (next.getQuantity() > sort[j-1].getQuantity())
                    {
                        newIndex = j;
                    }
                    else
                    {
                        sort[j] = sort[ j - 1 ];
                    }
                    j--;
                }
                else if (order == 0)
                {
                	//order descending
                	if (next.getQuantity() < sort[j-1].getQuantity())
                    {
                        newIndex = j;
                    }
                    else
                    {
                        sort[j] = sort[j - 1];
                    }
                    j--;
                }
            }
            
            //form new array with each element
            sort[newIndex] = next;
        }
        
        //return new array
        return sort;
    }
}
