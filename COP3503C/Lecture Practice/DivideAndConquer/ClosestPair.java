/* Dr. Steinberg
 *COP3503 Computer Science 2
 *Closest Pair of Points
 *ClosestPair.java
 */
import java.awt.Point;
import java.util.ArrayList;
import java.util.Collections;

public class ClosestPair
{
    //Brute Force Solution
    //Method to compute the Euclidean distance between two points
    public static double distance(Point p1, Point p2)
    {
        return Math.sqrt(Math.pow(p2.x - p1.x, 2) + Math.pow(p2.y - p1.y, 2));
    }

    //Brute force method to find the closest pair of points
    public static double closestPairBF(ArrayList<Point> points)
    {
        double minDistance = Double.MAX_VALUE;
        //Loop over all pairs of points
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                double dist = distance(points.get(i), points.get(j));
                minDistance = Math.min(minDistance, dist);
            }
        }
        return minDistance;
    }

    //Divide and Conquer Solution
    //Helper method to find the closest pair in the strip area
    public static double closestStrip(ArrayList<Point> strip, double delta)
    {
        double min = delta;
        for(int i = 0; i < strip.size(); i++)
        {
            for(int j = i + 1; j < strip.size() && (strip.get(j).y - strip.get(i).y) < min; j++)
            {
                min = Math.min(min, distance(strip.get(i), strip.get(j)));
            }
        }
        return min;
    }

    //Recursive method for Divide and Conquer approach
    public static double closestPairDCRec(ArrayList<Point> pointsSortX, ArrayList<Point> pointsSortY)
    {
        int n = pointsSortX.size();
        if (n <= 3)
        {
            return closestPairBF(pointsSortX);
        }
        int mid = n / 2;

        Point midPoint = pointsSortX.get(mid);

        ArrayList<Point> leftByX = new ArrayList<>(pointsSortX.subList(0, mid));
        ArrayList<Point> rightByX = new ArrayList<>(pointsSortX.subList(mid, n));

        ArrayList<Point> leftByY = new ArrayList<>();
        ArrayList<Point> rightByY = new ArrayList<>();

        for (Point p: pointsSortY)
        {
            if (p.x <= midPoint.x)
                leftByY.add(p);
            else
                rightByY.add(p);
        }

        // recursive call
        double leftDist = closestPairDCRec(leftByX, leftByY);
        double rightDist = closestPairDCRec(rightByX, rightByY);

        double delta = Math.min(leftDist, rightDist);
        
        // check the points in the strip area
        ArrayList<Point> strip = new ArrayList<>();
        for (Point p : pointsSortY)
        {
            if (Math.abs(p.x - midPoint.x) < delta)
                strip.add(p);
        }

        return Math.min(delta, closestStrip(strip, delta));
    }

    public static double closestPairDivideAndConquer(ArrayList<Point> points)
    {
        ArrayList<Point> pointsSortX = new ArrayList<Point>(points);
        ArrayList<Point> pointsSortY = new ArrayList<Point>(points);

        // sort the points
        Collections.sort(pointsSortX, (p1, p2) -> Integer.compare(p1.x, p2.x));
        Collections.sort(pointsSortY, (p1, p2) -> Integer.compare(p1.y, p2.y));

        return closestPairDCRec(pointsSortX, pointsSortY);
    }

    public static void main(String[] args)
    {
        ArrayList<Point> points = new ArrayList<Point>();
        // points.add(new Point(2, 3));
        // points.add(new Point(12, 30));
        // points.add(new Point(40, 50));
        // points.add(new Point(5, 1));
        // points.add(new Point(12, 10));
        // points.add(new Point(3, 4));
        points.add(new Point(7, 14));
        points.add(new Point(25, 3));
        points.add(new Point(18, 42));
        points.add(new Point(33, 12));
        points.add(new Point(9, 27));
        points.add(new Point(41, 8));
        points.add(new Point(14, 19));
        points.add(new Point(36, 29));
        points.add(new Point(22, 5));
        points.add(new Point(11, 33));
        points.add(new Point(28, 44));
        points.add(new Point(5, 17));
        points.add(new Point(47, 23));
        points.add(new Point(16, 7));
        points.add(new Point(8, 38));
        points.add(new Point(30, 15));
        points.add(new Point(19, 9));
        points.add(new Point(42, 31));
        points.add(new Point(6, 25));
        points.add(new Point(24, 40));

        //Brute Force closest pair
        System.out.println("Brute Force closest pair distance: " + closestPairBF(points));
        //Divide and Conquer closest pair
        System.out.println("Divide and Conquer closest pair distance: " + closestPairDivideAndConquer(points));
    }
}