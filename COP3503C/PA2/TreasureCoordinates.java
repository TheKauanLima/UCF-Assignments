/*  Kauan Lima
    Dr. Steinberg
    COP3503 Fall 2025
    Programming Assignment 2
*/
import java.util.ArrayList;
public class TreasureCoordinates
{
    public TreasureCoordinates()
    {
    }

    public ArrayList<String> determineCoordinates(String numbers)
    {
        // set up arrayList
        ArrayList<String> coordinates = new ArrayList<String>();

        // retrieve raw value
        numbers = numbers.substring(1, numbers.length()-1);

        return determineCoordinatesBT(coordinates, numbers, 1);
    }

    private ArrayList<String> determineCoordinatesBT(ArrayList<String> coords, String nums, int idx)
    {
        // check if index is at max val
        if (idx == nums.length())
            return coords;
        
        // separate x and y
        String xRaw = nums.substring(0, idx);
        String yRaw = nums.substring(idx);

        // find all possible x and y
        ArrayList<String> possibleX = variants(xRaw);
        ArrayList<String> possibleY = variants(yRaw);

        // construct the correct list
        for (String x : possibleX)
        {
            for (String y: possibleY)
            {
                coords.add("(" + x + ", " + y + ")");
            }
        }

        // scan through next index
        determineCoordinatesBT(coords, nums, idx+1);
        return coords;
    }

    private ArrayList<String> variants(String raw)
    {
        ArrayList<String> vars = new ArrayList<>();

        // check for leading 0s
        if (raw.length() > 1 && raw.charAt(0) == '0')
        {
            // add "." after the first 0
            String edit = raw.substring(0, 1) + "." + raw.substring(1);

            // filter out trailing zero possibilities
            if (edit.charAt(edit.length()-1) == '0')
                return vars;
            
            // add 0.x to list
            vars.add(edit);
            return vars;
        }

        // if not 0, add the raw number
        vars.add(raw);

        // add all possibilities with decimal
        for (int i = 1; i < raw.length(); i++)
        {
            String edit = raw.substring(0, i) + "." + raw.substring(i);
            vars.add(edit);
        }
        return vars;
    }
}