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
        ArrayList<String> coordinates = new ArrayList<String>();
        numbers = numbers.substring(1, numbers.length()-1);
        return determineCoordinatesBT(coordinates, numbers, 1);
    }

    private ArrayList<String> determineCoordinatesBT(ArrayList<String> coords, String nums, int idx)
    {
        if (idx == nums.length())
            return coords;
        
        String xRaw = nums.substring(0, idx);
        String yRaw = nums.substring(idx);
        ArrayList<String> possibleX = variants(xRaw);
        ArrayList<String> possibleY = variants(yRaw);
        for (String x : possibleX)
        {
            for (String y: possibleY)
            {
                coords.add("(" + x + ", " + y + ")");
            }
        }
        determineCoordinatesBT(coords, nums, idx+1);
        return coords;
    }

    private ArrayList<String> variants(String raw)
    {
        ArrayList<String> vars = new ArrayList<>();
        if (raw.length() > 1 && raw.charAt(0) == '0')
        {
            String edit = raw.substring(0, 1) + "." + raw.substring(1);
            vars.add(edit);
            return vars;
        }
        vars.add(raw);
        for (int i = 1; i < raw.length(); i++)
        {
            String edit = raw.substring(0, i) + "." + raw.substring(i);
            vars.add(edit);
        }
        return vars;
    }
}