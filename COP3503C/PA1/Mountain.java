/* Kauan Lima
 * Dr. Steinberg
 * COP3503 Fall 2025
 * Programming Assignment 1
 */
public class Mountain
{
    public static int getMaxElevationBF(int[] arr)
    {
        int lowest = arr[0];
        int highest = arr[0];
        int storedChange = 0;
        int elevationChange = 0;
        for (int i = 1; i < arr.length - 1; i++)
        {
            if (arr[i] < lowest)
                lowest = arr[i];
            for (int j = i; j < arr.length - 1; j++)
            {
                if (arr[j] > highest)
                    highest = arr[j];
            }
            storedChange = elevationChange;
            if (highest - lowest > storedChange)
                elevationChange = highest - lowest;
            highest = 0;
        }
        return elevationChange;
    }

    public static int getMaxElevation(int[] arr)
    {
        int lowest = arr[0];
        int highest = arr[0];
        int elevationChange = 0;
        for (int i = 1; i < arr.length - 1; i++)
        {
            if (arr[i] < lowest)
                lowest = arr[i];
            if (arr[i] > highest)
                highest = arr[i];
            elevationChange = highest - lowest;
            highest = 0;
        }

        return elevationChange;
    }
}