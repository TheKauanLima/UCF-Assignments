/* Kauan Lima
 * Dr. Steinberg
 * COP3503 Fall 2025
 * Programming Assignment 1
 */
public class Mountain
{
    // O(n^2) approach
    public static int getMaxElevationBF(int[] arr)
    {
        // set up variables
        int lowest = Integer.MAX_VALUE;
        int highest = Integer.MIN_VALUE;
        int storedChange = 0;
        int elevationChange = 0;

        // iterate through array
        for (int i = 1; i < arr.length - 1; i++)
        {
            // find lowest and highest points
            lowest = Math.min(lowest, arr[i]);
            for (int j = i; j < arr.length; j++)
                highest = Math.max(highest, arr[j]);

            // calculate elevation change
            storedChange = elevationChange;
            elevationChange = Math.max(storedChange, highest - lowest);

            // reset highest
            highest = 0;
        }

        return elevationChange;
    }

    // O(n) approach
    public static int getMaxElevation(int[] arr)
    {
        // set up variables
        int lowest = Integer.MAX_VALUE;
        int elevationChange = 0;

        // iterate through array
        for (int i = 1; i < arr.length; i++)
        {
            // evaluate elevationChange
            elevationChange = Math.max(elevationChange, arr[i] - lowest);
            // evaluate lowest
            lowest = Math.min(lowest, arr[i]);
        }

        return elevationChange;
    }
}