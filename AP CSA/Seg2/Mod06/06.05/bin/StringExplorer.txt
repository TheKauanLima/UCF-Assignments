/**
 * A program to allow students to try out different
 * String methods.
 *
 * Code adapted from work by Laurie White for the College Board.
 *
 * @author Kauan Lima
 * @version 1/17/2024
 */
public class StringExplorer
{

    public static void main(String[] args)
    {
        String sample = "The quick brown fox jumped over the lazy dog.";
        System.out.println("sample = " + sample);
        System.out.println();

        //  Demonstrate the indexOf method.
        int position = sample.indexOf("quick");
        System.out.println("sample.indexOf(\"quick\") = " + position);

        int notFoundPos  = sample.indexOf("slow");
        System.out.println("sample.indexOf(\"slow\") = " + notFoundPos);

        position = sample.indexOf("o");
        System.out.println("sample.indexOf(\"o\") = "+ position);
        position = sample.indexOf("o", position + 1);
        System.out.println("sample.indexOf(\"o\", position + 1) = " + position);

        System.out.println();

        //  Demonstrate the toLowerCase method.
        String lowerCase = sample.toLowerCase();
        System.out.println("sample.toLowerCase() = " + lowerCase);
        System.out.println("After toLowerCase(), sample = " + sample);
        System.out.println();

        boolean isEqual = sample.equals(sample.toLowerCase());
        System.out.println("sample.equals(sample.toLowerCase() = "+ isEqual);

        // Assign a new value to sample. Use a phrase of your choosing.
        // Pad the beginning and end of the string literal with spaces.
        sample = "    How many times will we have to teach you this lesson?             ";

        //  Add examples below for the following methods:
        //    trim()
        System.out.println(sample.trim());
        
        //    length()
        System.out.println(sample.length());
        
        //    indexOf with one and two parameters
        System.out.println(sample.indexOf("a"));
        System.out.println(sample.indexOf("a", 18));
        
        //    substring() with one and two parameters
        System.out.println(sample.substring(5));
        System.out.println(sample.substring(6, 18));
        
        //    compareTo()
        String sampleUpper = sample.toUpperCase(); //    any other String methods you'd like to try
        System.out.println(sample.compareTo(sampleUpper));
    }
}
