/**
 * @purpose: Search through various songs in a collection by title, year, and artist.
 * 
 * @author Kauan Lima
 * @version 3/3/2024
 */
public class MusicTesterV1
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
        
        System.out.println("\n\nSearching for Despacito: ");
        findTitle(titles, "Despacito");
        
        System.out.println("\n\nSearching for 1991: ");
        findYear(titles, 1991);
        
        System.out.println("\n\nSearching for Guns N' Roses: ");
        findArtist(titles, "Guns N' Roses");
	}
	
	//print the original data
	public static void printTitles(Music[] titles)
    {
        System.out.println("Title                     Year   Artist");
        System.out.println("-------------------------------------------------------");
        for(int i = 0; i < titles.length; i++)
            System.out.println(titles[i]);
    }
   
	//search for song title
    public static void findTitle(Music[] titles, String toFind)
    {
        int in = -1;

        for(int i = 0; i < titles.length; i++)
        {
            if(titles[i].getTitle().compareTo(toFind) == 0)
            {
                in = i;
                break;   //terminates the for loop 
            }
        }
        
        if(in != -1)
        {  // we have found the title
            System.out.println("We found " + toFind + " in the collection: ");
            System.out.println(titles[in]);
        }
        else
            System.out.println(toFind + " is not in the collection");
    }
   
    //search for song year
    public static void findYear(Music[] titles, int year)
    {
        int in = -1;
        int start = 0;
        int conditionCheck = 0;

        while(conditionCheck == 0)
        {
        	for(int i = start; i < titles.length; i++)
            {
                if(titles[i].getYear() == year)
                {
                    in = i;
                    break;   //terminates the for loop 
                }
            }
            
            if(in != -1 && start == 0)
            {  // we have found the year
                System.out.println("We found " + year + " in the collection: ");
                System.out.println(titles[in]);
            }
            else if(in != -1 && start != 0)
            {  // we have found the year
                System.out.println(titles[in]);
            }
            else
                System.out.println(year + " is not in the collection");
            
            for(int i = in + 1; i < titles.length; i++)
            {
                if(titles[i].getYear() == year)
                {
                    start = i;
                    conditionCheck = 0;
                    break;   //terminates the for loop 
                }
                else
                {
                	conditionCheck = 1;
                }
            }
        }
    }
    
    //search for song by artist
    public static void findArtist(Music[] titles, String toFind)
    {
        int in = -1;
        int start = 0;
        int conditionCheck = 0;

        while (conditionCheck == 0)
        {
        	for(int i = start; i < titles.length; i++)
            {
                if(titles[i].getArtist().compareTo(toFind) == 0)
                {
                    in = i;
                    break;   //terminates the for loop 
                }
            }
            
            if(in != -1 && start == 0)
            {  // we have found the artist
                System.out.println("We found " + toFind + " in the collection: ");
                System.out.println(titles[in]);
            }
            else if(in != -1 && start != 0)
            {  // we have found the artist
                System.out.println(titles[in]);
            }
            else
                System.out.println(toFind + " is not in the collection");
            
            
            for(int i = in + 1; i < titles.length; i++)
            {
                if(titles[i].getArtist().compareTo(toFind) == 0)
                {
                    start = i;
                    conditionCheck = 0;
                    break;   //terminates the for loop 
                }
                else conditionCheck = 1;
            }
        }
    }
}