/**
 * Purpose: Sort an unsorted array of different movies with selection sort by different criteria (title, year, studio)
 *
 * @author Kauan Lima
 * @version 2/25/24
 *
 */
public class MovieTesterV3
{
	public static void main(String[] args)
	{
		//declare necessary arrays
		Movie[] movies = new Movie[10];
        Movie[] sorted = new Movie[10];

        //initialize the catalog of movies
        movies[0] = new Movie("Meet the Robinsons", 2007, "Disney");
        movies[1] = new Movie("Bullet Train", 2022, "Sony");
        movies[2] = new Movie("Gladiator", 2000, "Dreamworks");
        movies[3] = new Movie("Jujutsu Kaisen 0", 2021, "MAPPA");
        movies[4] = new Movie("21 Jump Street", 2012, "Columbia Pictures");
        movies[5] = new Movie("Don't Look Up", 2021, "Netflix");
        movies[6] = new Movie("Happy Death Day", 2017, "Blumhouse");
        movies[7] = new Movie("Oppenheimer", 2023, "Universal");
        movies[8] = new Movie("Idiocracy", 2006, "20th Century Fox");
        movies[9] = new Movie("Ferris Bueller's Day Off", 1986, "Paramount Pictures");
        
        //print the initial, unsorted array
        System.out.println("    <<<< Before Sorting >>>> \n");
        printMovies(movies);

        
        //sort by title
        //alphabetical order
        sorted = sortByTitle(movies, 1);
        System.out.println("\n     <<<< After Sorting >>>>");
        System.out.println("<<<< by title in alphabetical order >>>>\n");
        printMovies(sorted);
           
        //reverse-alphabetical order
        sorted = sortByTitle(movies, 2);
        System.out.println("\n     <<<< After Sorting >>>>");
        System.out.println("<<<< by title in reverse-alphabetical order >>>>\n");
        printMovies(sorted);
        
        
        //sort by year
        //ascending order
        sorted = sortByYear(movies, 1);
        System.out.println("\n     <<<< After Sorting >>>>");
        System.out.println("<<<< by year in ascending order >>>>\n");
        printMovies(sorted);
            
        //descending order
        sorted = sortByYear(movies, 2);
        System.out.println("\n     <<<< After Sorting >>>>");
        System.out.println("<<<< by year in descending order >>>>\n");
        printMovies(sorted);
            
        
        //sort by studio
        //alphabetical order
        sorted = sortByStudio(movies, 1);
        System.out.println("\n     <<<< After Sorting >>>>");
        System.out.println("<<<< by studio in alphabetical order >>>>\n");
        printMovies(sorted);   
        
        //reverse-alphabetical order
        sorted = sortByStudio(movies, 2);
        System.out.println("\n     <<<< After Sorting >>>>");
        System.out.println("<<<< by studio in reverse-alphabetical order >>>>\n");
        printMovies(sorted);  
    }
    
	//print each element of the array
	public static void printMovies(Movie[] data)
	{
		for(int i = 0; i < data.length; i++)
            System.out.println(data[i]);
	}
	
	//sort by title
	public static Movie[] sortByTitle(Movie[] original, int order)
	{
		//declare necessary variables
	    int i;
	    int j;
	    int posMax;
	    Movie temp;

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
	            	if (original[j].getTitle().compareTo(original[posMax].getTitle()) > 0)
	                    posMax = j;
	            }
	            else if (order == 2)
	            {
	            	if (original[j].getTitle().compareTo(original[posMax].getTitle()) < 0)
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
		
	//sort by year
	public static Movie[] sortByYear(Movie[] original, int order)
    {
		//declare necessary variables
        int i;
        int j;
        int posMax;
        Movie temp;

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
                	if (original[j].getYear() > original[posMax].getYear())
                        posMax = j;
                }
                else if (order == 2)
                {
                	if (original[j].getYear() < original[posMax].getYear())
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
	
	//sort by studio
	public static Movie[] sortByStudio(Movie[] original, int order)
	{
		//declare necessary variables
		int i;
		int j;
		int posMax;
		Movie temp;

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
		        	if (original[j].getStudio().compareTo(original[posMax].getStudio()) > 0)
		                posMax = j;
		        }
		        else if (order == 2)
		        {
		        	if (original[j].getStudio().compareTo(original[posMax].getStudio()) < 0)
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
}