/* Kauan Lima
 * Dr. Steinberg
 * COP3503 Fall 2025
 * Programming Assignment 4
 */

import java.io.*;
import java.util.*;

public class DroneDelivery
{
    // job class
    private class Job 
    {
        // private instance variables
        private String ID;
        private int distance;
        private int weight;
        private int value;
        private int battery;

        // constructor 
        private Job(String id, int dist, int wt, int val)
        {
            // assign values
            ID = id;
            distance = dist;
            weight = wt;
            value = val;

            // calculate battery
            double perKm = 1.0 + 0.1 * weight;
            double total = distance * perKm;
            battery = (int)Math.round(total * 10); // multiplied 10 for future array indexing
        }
    }

    private ArrayList<Job> jobs; // job list
    private int n; // number of jobs
    private int scale = 10; // battery scaling variable

    // tabulation variables
    private boolean[][][] chosen = null;
    private int[][][] tab = null;
    private int holdP, holdB;

    // constructor
    public DroneDelivery(String filename)
    {
        jobs = new ArrayList<>();

        // read file line by line
        try (BufferedReader br = new BufferedReader(new FileReader(filename)))
        {
            String ln;
            while ((ln = br.readLine()) != null)
            {
                // tokenize line
                String[] tokens = ln.split("\\s+");

                // set required values to the different tokens
                String id = tokens[0];
                int dist = Integer.parseInt(tokens[1]);
                int wt = Integer.parseInt(tokens[2]);
                int val = Integer.parseInt(tokens[3]);

                // add a new job
                jobs.add(new Job(id, dist, wt, val));
            }
        }
        // exception handling
        catch (IOException ex)
        {
            throw new RuntimeException("IO error: " + ex);
        }

        // set number of jobs
        n = jobs.size();
    }

    // recursion
    public int maxCostRecursive(double maxBatteryLife, int payloadCapacity)
    {
        int battery = scaleBattery(maxBatteryLife, scale); // scale for array indexing

        return rec(0, payloadCapacity, battery);
    }

    private int rec(int i, int p, int b)
    {
        if (i == n)
            return 0;

        int noJob, chosenJob = 0;

        // find value if job isn't chosen
        noJob = rec(i + 1, p, b);

        // match capacity and battery, and find value if job chosen
        Job job = jobs.get(i);
        if (job.weight <= p && job.battery <= b)
            chosenJob = job.value + rec(i + 1, p - job.weight, b - job.battery);
        
        // return best answer
        return Math.max(noJob, chosenJob);
    }

    // memoization
    public int maxCostMemo(double maxBatteryLife, int payloadCapacity)
    {
        int battery = scaleBattery(maxBatteryLife, scale);
        int[][][] memo = new int[n + 1][payloadCapacity + 1][battery + 1];

        return memoi(0, payloadCapacity, battery, memo);
    }

    private int memoi(int i, int p, int b, int[][][] memo)
    {
        if (i == n)
            return 0;

        // skip if solution found
        if (memo[i][p][b] != 0)
            return memo[i][p][b];

        int noJob, chosenJob = 0;

        // find value if job isn't chosen
        noJob = rec(i + 1, p, b);

        // match capacity and battery, and find value if job chosen
        Job job = jobs.get(i);
        if (job.weight <= p && job.battery <= b)
            chosenJob = job.value + memoi(i + 1, p - job.weight, b - job.battery, memo);

        // return best answer
        memo[i][p][b] = Math.max(noJob, chosenJob);
        return memo[i][p][b];
    }

    // tabulation
    public int maxCostTab(double maxBatteryLife, int p)
    {
        int b = scaleBattery(maxBatteryLife, scale);

        tab = new int[n + 1][p + 1][b + 1];
        chosen = new boolean[n + 1][p + 1][b + 1];

        // tabulation
        for (int i = 1; i <= n; i++)
        {
            Job job = jobs.get(i - 1);
            for (int cap = 0; cap <= p; cap++)
            {
                for (int bat = 0; bat <= b; bat++)
                {
                    // value if job not chosen
                    int noJob = tab[i - 1][cap][bat];
                    int chosenJob = 0;
                    boolean choose = false;

                    // choose job(i-1) if better
                    if (job.weight <= cap && job.battery <= bat)
                    {
                        chosenJob = job.value + tab[i - 1][cap - job.weight][bat - job.battery];
                        if (chosenJob > noJob)
                            choose = true;
                    }

                    // update tabulation and mark if this job was chosen
                    tab[i][cap][bat] = choose ? chosenJob : noJob;
                    chosen[i][cap][bat] = choose;
                }
            }
        }

        // keep values of p and b for display
        holdP = p;
        holdB = b;

        // return final value in tabulation
        return tab[n][p][b];
    }

    // display the chosen jobs
    public void displaySelectedJobs()
    {
        int p = holdP;
        int b = holdB;
        List<String> chosenJobs = new ArrayList<>();

        // trek through chosen table backwards to find all jobs
        for (int i = n; i > 0; i--)
        {
            if (chosen[i][p][b])
            {
                Job job = jobs.get(i - 1);
                chosenJobs.add(job.ID);
                p -= job.weight;
                b -= job.battery;
            }
        }

        // print jobs
        Collections.reverse(chosenJobs); // restore original order
        for (String ID : chosenJobs)
            System.out.println(ID);
    }

    // scale battery for array implementations
    private int scaleBattery(double b, int scale)
    {
        return (int)Math.round(b * scale);
    }
}
