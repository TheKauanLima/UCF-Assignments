/**
 * @purpose: Search through various songs in a collection by title, year, and artist.
 * 
 * @author Kauan Lima
 * @version 3/8/2024
 */
public class MusicTesterV2
{
	public static void main(String[] args)
	{
		//create array
		Music[] titles = new Music[10];
        
        titles[0] = new Music("Livin' on a Prayer", 1986, "Bon Jovi");
        titles[1] = new Music("November Rain", 1991, "Guns N' Roses");
        titles[2] = new Music("Smooth Operator", 1984, "Sade");
        titles[3] = new Music("The Hustle", 1975, "Van McCoy");
        titles[4] = new Music("Matte Kudasai", 1981, "King Crimson");
        titles[5] = new Music("Knockin' On Heaven's Door", 1991, "Guns N' Roses");
        titles[6] = new Music("Get Lucky", 2013, "Daft Punk");
        titles[7] = new Music("Despacito", 2017, "Luis Fonsi");
        titles[8] = new Music("Hey Ya!", 2003, "OutKast");
        titles[9] = new Music("Blinding Lights", 2020, "The Weeknd");
        
        //print original data and all searched data
        printTitles(titles);
        System.out.println();
        
        //sort by title and find a specific title
        Music[] newTitles = insertionSortByTitle(titles);
        String toFindTitle = "Despacito";
        System.out.println("\n\nSearching for " + toFindTitle + ":");
        int test = binarySearchTitle(newTitles, toFindTitle);
        if(test != -1)
            System.out.println(newTitles[test]);
        else
            System.out.println("NOT found: " + toFindTitle);
        
        toFindTitle = "Where Our Blue Is";
        System.out.println("\n\nSearching for " + toFindTitle + ":");
        test = binarySearchTitle(newTitles, toFindTitle);
        if(test != -1)
            System.out.println(newTitles[test]);
        else
            System.out.println("NOT found: " + toFindTitle);
        
        
        
        //sort by year and find a specific year
        Music[] newYears = insertionSortByYear(titles);
        System.out.println("\n\nSearching for 1991: ");
        binarySearchYear(newYears, 1991);
        
        System.out.println("\n\nSearching for 2021: ");
        binarySearchYear(newYears, 2021);
        
        
        
        //sort by artist and find a specific artist
        Music[] newArtist = insertionSortByArtist(titles);
        System.out.println("\n\nSearching for Guns N' Roses: ");
        binarySearchArtist(newArtist, "Guns N' Roses");
        
        System.out.println("\n\nSearching for Tyler the Creator: ");
        binarySearchArtist(newArtist, "Tyler the Creator");
	}
	
	//print the original data
	public static void printTitles(Music[] titles)
    {
        System.out.println("Title                     Year   Artist");
        System.out.println("-------------------------------------------------------");
        for(int i = 0; i < titles.length; i++)
            System.out.println(titles[i]);
    }

    
	
	
	//sorting arrays
	//sort the array in descending order by the title
	public static Music[] insertionSortByTitle(Music[] original)
	{
		//create new array for sorting
	    Music[] sort = new Music[original.length];

	    //insertion sort loop
	    for (int i = 0 ; i < original.length ; i++)
	    {
	        //create necessary variables: current array information, current index, previous index
	        Music next = original[i];
	        int newIndex = 0;
	        int j = i;
	            
	        //start checking from the second element
	        while (j > 0 && newIndex == 0)
	        {
	                //order ascending
	                if (next.getTitle().compareTo(sort[j-1].getTitle()) > 0)
	                    newIndex = j;
	                else
	                    sort[j] = sort[ j - 1 ];
	                j--;
	        }
	            
	        //form new array with each element
	        sort[newIndex] = next;
	    }
	        
	    //return new array
	    /*for(int i = 0; i <sort.length; i++)
	    {
	    	System.out.println(sort[i]);
	    }*/
	    return sort;
	}
	
	//sort the array in descending order by the year
    public static Music[] insertionSortByYear(Music[] original)
    {
    	//create new array for sorting
	    Music[] sort = new Music[original.length];

	    //insertion sort loop
	    for (int i = 0 ; i < original.length ; i++)
	    {
	        //create necessary variables: current array information, current index, previous index
	        Music next = original[i];
	        int newIndex = 0;
	        int j = i;
	            
	        //start checking from the second element
	        while (j > 0 && newIndex == 0)
	        {
	                //order ascending
	                if (next.getYear() > sort[j-1].getYear())
	                    newIndex = j;
	                else
	                    sort[j] = sort[ j - 1 ];
	                j--;
	        }
	            
	        //form new array with each element
	        sort[newIndex] = next;
	    }
	        
	    //return new array
	    /*for(int i = 0; i <sort.length; i++)
	    {
	    	System.out.println(sort[i]);
	    }*/
	    return sort;
    }
    
	//sort the array in descending order by the artist
	public static Music[] insertionSortByArtist(Music[] original)
	{
		//create new array for sorting
	    Music[] sort = new Music[original.length];

	    //insertion sort loop
	    for (int i = 0 ; i < original.length ; i++)
	    {
	        //create necessary variables: current array information, current index, previous index
	        Music next = original[i];
	        int newIndex = 0;
	        int j = i;
	            
	        //start checking from the second element
	        while (j > 0 && newIndex == 0)
	        {
	                //order ascending
	                if (next.getArtist().compareTo(sort[j-1].getArtist()) > 0)
	                    newIndex = j;
	                else
	                    sort[j] = sort[ j - 1 ];
	                j--;
	        }
	            
	        //form new array with each element
	        sort[newIndex] = next;
	    }
	        
	    //return new array
	    /*for(int i = 0; i <sort.length; i++)
	    {
	    	System.out.println(sort[i]);
	    }*/
	    return sort;
	}
    
    
    
    //search sorted arrays
    //search a sorted array for a title
    public static int binarySearchTitle(Music[] sorted, String toFind )
    {
        int high = sorted.length;
        int low = -1;
        int middle;

        while( high - low > 1 )
        {
            middle = ( high + low ) / 2;
            
            if(sorted[middle].getTitle().compareTo(toFind) > 0)
                high = middle;
            else
                low = middle;
        }
        
        if( (low >= 0) && (sorted[low].getTitle().compareTo(toFind) == 0 ))
            return low;
        else
            return -1;
    }
    
    //search a sorted array for a year
    public static void binarySearchYear(Music[] sorted, int toFind)
    {
    	 int high = sorted.length;
         int low = -1;
         int middle;

         while( high - low > 1 )
         {
             middle = ( high + low ) / 2;

             if(sorted[middle].getYear() > toFind)
                 high = middle;
             else
             {
                 low = middle;
                 if(sorted[middle].getYear() == toFind)
                 {
                     break;
                 }
             }
         }
         
         if( (low >= 0) && (sorted[low].getYear() == toFind))
         {
             linearPrintYear(sorted, low, toFind);
         }
         else
             System.out.println("NOT found: " + toFind);
    }
    
    //print all instances of a year
    public static void linearPrintYear(Music[] sorted, int low, int toFind)
    {
        int i;
        int start = low;
        int end = low;

        // find starting point of matches
        i = low - 1;
        while((i >= 0) && (sorted[i].getYear() == toFind))
        {
            start = i;
            i--;
        }
        // find ending point of matches
        i = low + 1;
        while((i < sorted.length) && (sorted[i].getYear() == toFind))
        {
            end = i;
            i++;
        }
        // now print out the matches
        for(i = start; i <= end; i++)
            System.out.println(sorted[i]);
    }
    
    //search a sorted array for an artist
    public static void binarySearchArtist(Music[] sorted, String toFind)
    {
    	 int high = sorted.length;
         int low = -1;
         int middle;

         while( high - low > 1 )
         {
             middle = ( high + low ) / 2;

             if(sorted[middle].getArtist().compareTo(toFind) > 0)
                 high = middle;
             else
             {
                 low = middle;
                 if(sorted[middle].getArtist().compareTo(toFind) == 0)
                 {
                     break;
                 }
             }
         }
         
         if( (low >= 0) && (sorted[low].getArtist().compareTo(toFind) == 0))
         {
             linearPrintArtist(sorted, low, toFind);
         }
         else
             System.out.println("NOT found: " + toFind);
    }
    
    //print all instances of an artist
    public static void linearPrintArtist(Music[] sorted, int low, String toFind)
    {
        int i;
        int start = low;
        int end = low;

        // find starting point of matches
        i = low - 1;
        while((i >= 0) && (sorted[i].getArtist().compareTo(toFind) == 0))
        {
            start = i;
            i--;
        }
        // find ending point of matches
        i = low + 1;
        while((i < sorted.length) && (sorted[i].getArtist().compareTo(toFind) == 0))
        {
            end = i;
            i++;
        }
        // now print out the matches
        for(i = start; i <= end; i++)
            System.out.println(sorted[i]);
    }
}