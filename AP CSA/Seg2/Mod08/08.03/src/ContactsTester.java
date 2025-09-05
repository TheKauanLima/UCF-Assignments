/**
 * @purpose: Tester class to sort and find different elements in an array of objects.
 * 
 * @author Kauan Lima
 * @version 3/10/2024
 */
public class ContactsTester
{
	public static void main(String[] args)
	{
		//create arrays
		Contact[] contacts = new Contact[10];

		//initialize arrays
		contacts[0] = new Contact("Cristina Lima", "mom", "Nov 24", "301-987-6371", "cristina@gmail.lima");
		contacts[1] = new Contact("Ivan Lima", "dad", "Sep 3", "301-827-1036", "ivan@gmail.lima");
		contacts[2] = new Contact("Adam Helfi", "friend", "Sep 18", "297-195-2859", "adam@gmail.helfi");
		contacts[3] = new Contact("Dylan Orndorff", "friend", "Aug 25", "189-209-5839", "dylan@gmail.orndorff");
		contacts[4] = new Contact("Emily Mirallia", "cousin", "Jan 2", "937-174-1056", "emily@gmail.mirallia");
		contacts[5] = new Contact("Camila Mirallia", "cousin", "Sep 17", "937-174-1056", "emily@gmail.mirallia");
		contacts[6] = new Contact("Ren Amamiya", "friend", "Oct 7", "612-8631-4829", "persona@gmail.royal");
		contacts[7] = new Contact("Jefferson Christ", "friend", "Feb 27", "837-105-2847", "jefferson@gmail.christ");
		contacts[8] = new Contact("Elisa Moura", "aunt", "Mar 5", "765-926-0954", "elisa@gmail.moura");
		contacts[9] = new Contact("Kauan Lima", "me", "Oct 12", "903-726-8556", "kauan@gmail.lima");
		
		//print original data and all searched data
        printContacts(contacts);
        System.out.println();
        
        //sort by title and find a specific title
        Contact[] sortedNames = insertionSortByName(contacts);
        String toFindName = "Ivan Lima";
        
        System.out.println("\n\n<< Searching for name: " + toFindName + " >>");
        int test = binarySearchName(sortedNames, toFindName);
        if(test != -1)
            System.out.println(sortedNames[test]);
        else
            System.out.println("NOT found: " + toFindName);
        
        
        toFindName = "Clara Lima";
        System.out.println("\n\n<< Searching for name: " + toFindName + " >>");
        test = binarySearchName(sortedNames, toFindName);
        if(test != -1)
            System.out.println(sortedNames[test]);
        else
            System.out.println("NOT found: " + toFindName);
        
        
        
        //sort by year and find a specific year
        Contact[] sortedRelations = insertionSortByRelation(contacts);
        String toFindRelation = "friend";
        
        System.out.println("\n\n<< Searching for relation: " + toFindRelation + " >>");
        binarySearchRelation(sortedRelations, toFindRelation);
        
        toFindRelation = "sister";
        System.out.println("\n\n<< Searching for relation: " + toFindRelation + " >>");
        binarySearchRelation(sortedRelations, toFindRelation);
        
        
        
        
        //find birth month, if shared, print all results
        String toFindBirthMonth = "Sep";
        System.out.println("\n\n<< Searching for birth month: " + toFindBirthMonth + " >>");
        findMonth(contacts, toFindBirthMonth);
        
        toFindBirthMonth = "Apr";
        System.out.println("\n\n<< Searching for birth month: " + toFindBirthMonth + " >>");
        findMonth(contacts, toFindBirthMonth);
        
        
        
        //find phone number, if shared, print all results
        String toFindPhoneNumber = "937-174-1056";
        System.out.println("\n\n<< Searching for phone number: " + toFindPhoneNumber + " >>");
        findPhoneNumber(contacts, toFindPhoneNumber);
        
        toFindPhoneNumber = "101-392-8865";
        System.out.println("\n\n<< Searching for phone number: " + toFindPhoneNumber + " >>");
        findPhoneNumber(contacts, toFindPhoneNumber);
        
        
        //find email address, if shared, print all results
        String toFindEmail = "emily@gmail.mirallia";
        System.out.println("\n\n<< Searching for email address: " + toFindEmail + " >>");
        findEmail(contacts, toFindEmail);
        
        toFindEmail = "ren@gmail.amamiya";
        System.out.println("\n\n<< Searching for email address: " + toFindEmail + " >>");
        findEmail(contacts, toFindEmail);
	}
	
	
	
	//print the original data
	public static void printContacts(Contact[] contacts)
	{
	    System.out.println("Name               Relation               Birthdate               Phone Number               Email Address");
	    System.out.println("------------------------------------------------------------------------------------------------------------");
	    for(int i = 0; i < contacts.length; i++)
	        System.out.println(contacts[i]);
	}
	
	
	
	//sorting arrays
	//sort the array in descending order by the name
	public static Contact[] insertionSortByName(Contact[] original)
	{
		//create new array for sorting
	    Contact[] sort = new Contact[original.length];

	    //insertion sort loop
	    for (int i = 0 ; i < original.length ; i++)
	    {
	        //create necessary variables: current array information, current index, previous index
	        Contact next = original[i];
	        int newIndex = 0;
	        int j = i;
	            
	        //start checking from the second element
	        while (j > 0 && newIndex == 0)
	        {
	                //order ascending
	                if (next.getName().compareTo(sort[j-1].getName()) > 0)
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
	
	//sort the array in descending order by the relation
	public static Contact[] insertionSortByRelation(Contact[] original)
	{
		//create new array for sorting
	    Contact[] sort = new Contact[original.length];

	    //insertion sort loop
	    for (int i = 0 ; i < original.length ; i++)
	    {
	        //create necessary variables: current array information, current index, previous index
	        Contact next = original[i];
	        int newIndex = 0;
	        int j = i;
	            
	        //start checking from the second element
	        while (j > 0 && newIndex == 0)
	        {
	                //order ascending
	                if (next.getRelation().compareTo(sort[j-1].getRelation()) > 0)
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
	
	
	
    //binary search sorted arrays
    //search a sorted array for a name
    public static int binarySearchName(Contact[] sorted, String toFind )
    {
        int high = sorted.length;
        int low = -1;
        int middle;

        while( high - low > 1 )
        {
            middle = ( high + low ) / 2;
            
            if(sorted[middle].getName().compareTo(toFind) > 0)
                high = middle;
            else
                low = middle;
        }
        
        if( (low >= 0) && (sorted[low].getName().compareTo(toFind) == 0 ))
            return low;
        else
            return -1;
    }
    
    //search a sorted array for a relation
    public static void binarySearchRelation(Contact[] sorted, String toFind)
    {
    	 int high = sorted.length;
         int low = -1;
         int middle;

         while( high - low > 1 )
         {
             middle = ( high + low ) / 2;

             if(sorted[middle].getRelation().compareTo(toFind) > 0)
                 high = middle;
             else
             {
                 low = middle;
                 if(sorted[middle].getRelation().compareTo(toFind) == 0)
                 {
                     break;
                 }
             }
         }
         
         if( (low >= 0) && (sorted[low].getRelation().compareTo(toFind) == 0))
         {
             linearPrintRelation(sorted, low, toFind);
         }
         else
             System.out.println("NOT found: " + toFind);
    }
    
    //print all instances of a relation
    public static void linearPrintRelation(Contact[] sorted, int low, String toFind)
    {
        int i;
        int start = low;
        int end = low;

        // find starting point of matches
        i = low - 1;
        while((i >= 0) && (sorted[i].getRelation().compareTo(toFind) == 0))
        {
            start = i;
            i--;
        }
        // find ending point of matches
        i = low + 1;
        while((i < sorted.length) && (sorted[i].getRelation().compareTo(toFind) == 0))
        {
            end = i;
            i++;
        }
        // now print out the matches
        for(i = start; i <= end; i++)
            System.out.println(sorted[i]);
    }

    //find specific phone number
    public static void findPhoneNumber(Contact[] contacts, String toFind)
    {
        int in = -1;
        int start = 0;
        int conditionCheck = 0;

        while (conditionCheck == 0)
        {
        	for(int i = start; i < contacts.length; i++)
            {
                if(contacts[i].getPhoneNumber().compareTo(toFind) == 0)
                {
                    in = i;
                    break;   //terminates the for loop 
                }
            }
            
            if(in != -1 && start == 0)
            {  // we have found the phone number
                System.out.println("We found " + toFind + " in the collection: ");
                System.out.println(contacts[in]);
            }
            else if(in != -1 && start != 0)
            {  // we have not found the phone number
                System.out.println(contacts[in]);
            }
            else
                System.out.println(toFind + " is not in the collection");
            
            
            for(int i = in + 1; i < contacts.length; i++)
            {
                if(contacts[i].getPhoneNumber().compareTo(toFind) == 0)
                {
                    start = i;
                    conditionCheck = 0;
                    break;   //terminates the for loop 
                }
                else conditionCheck = 1;
            }
        }
    }
    
    //find specific email address
    public static void findEmail(Contact[] contacts, String toFind)
    {
        int in = -1;
        int start = 0;
        int conditionCheck = 0;

        while (conditionCheck == 0)
        {
        	for(int i = start; i < contacts.length; i++)
            {
                if(contacts[i].getEmailAddress().compareTo(toFind) == 0)
                {
                    in = i;
                    break;   //terminates the for loop 
                }
            }
            
            if(in != -1 && start == 0)
            {  // we have found the email
                System.out.println("We found " + toFind + " in the collection: ");
                System.out.println(contacts[in]);
            }
            else if(in != -1 && start != 0)
            {  // we have not found the email
                System.out.println(contacts[in]);
            }
            else
                System.out.println(toFind + " is not in the collection");
            
            
            for(int i = in + 1; i < contacts.length; i++)
            {
                if(contacts[i].getEmailAddress().compareTo(toFind) == 0)
                {
                    start = i;
                    conditionCheck = 0;
                    break;   //terminates the for loop 
                }
                else conditionCheck = 1;
            }
        }
    }
    
    //find specific month
    public static void findMonth(Contact[] contacts, String toFind)
    {
        int in = -1;
        int start = 0;
        int conditionCheck = 0;
        String monthSubString;
        int spaceOfMonth;

        while (conditionCheck == 0)
        {
        	for(int i = start; i < contacts.length; i++)
            {
        		spaceOfMonth = contacts[i].getBirthday().indexOf(" ");
        		monthSubString = contacts[i].getBirthday().substring(0, spaceOfMonth);
        		
                if(monthSubString.compareTo(toFind) == 0)
                {
                    in = i;
                    break;   //terminates the for loop 
                }
            }
            
            if(in != -1 && start == 0)
            {  // we have found the month
                System.out.println("We found " + toFind + " in the collection: ");
                System.out.println(contacts[in]);
            }
            else if(in != -1 && start != 0)
            {  // we have not found the month
                System.out.println(contacts[in]);
            }
            else
                System.out.println(toFind + " is not in the collection");
            
            
            for(int i = in + 1; i < contacts.length; i++)
            {
            	spaceOfMonth = contacts[i].getBirthday().indexOf(" ");
        		monthSubString = contacts[i].getBirthday().substring(0, spaceOfMonth);
        		
                if(monthSubString.compareTo(toFind) == 0)
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