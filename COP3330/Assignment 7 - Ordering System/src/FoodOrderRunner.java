/**
 * Kauan Lima
 * Assignment 7: Ordering System
 * COP 3330
 * 4/13/2025
 */
// all imports
import java.io.FileReader;
import java.io.IOException;
import java.util.PriorityQueue;
import java.io.BufferedReader;
import java.io.FileNotFoundException;

public class FoodOrderRunner {
	// main
	public static void main(String[] args) {
		// instantiate new priority queue
		PriorityQueue<FoodOrder> pq = new PriorityQueue<FoodOrder>();
		
		// check for all possible filenames
		String[] fileNames = { "a7a.txt", "a7b.txt", "a7c.txt" };
		
		// iterate for each filename
		for (String filename : fileNames) {
			// try catch block with a buffered reader of the file
			try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
				// find the # of iterations of the file
				String iter = (String)br.readLine();
				int numIter = Integer.parseInt(iter);
				
				// iterate the required amount
				for (int i = 0; i < numIter; i++) {
					// obtain the inputs by splitting at the delimiter "\\s"
					String line = br.readLine();
					String regex = "[\\s]";
					String[] inputs = line.split(regex);
					
					// check which input was made
					// insert item to priority queue
					if (inputs[0].compareTo("INSERT") == 0) {
						// obtain the priority (lower number = higher priority)
						int priority = Integer.parseInt(inputs[4]);
						
						// create the correct kind of object and add to the pq
						if (inputs[1].compareTo("DINEIN") == 0) {
							DineInOrder di = new DineInOrder(inputs[2], inputs[3], priority);
							pq.add(di);
						} else if (inputs[1].compareTo("TAKEOUT") == 0) {
							TakeoutOrder to = new TakeoutOrder(inputs[2], inputs[3], priority);
							pq.add(to);
						} else if (inputs[1].compareTo("DELIVERY") == 0) {
							DeliveryOrder d = new DeliveryOrder(inputs[2], inputs[3], priority);
							pq.add(d);
						}
					}
					// prepare the item first in the queue (lowest number)
					else if (inputs[0].compareTo("PREPARE") == 0) {
						// peek at the current item
						FoodOrder head = pq.peek();
						if (head != null) {
							// prepare the order and poll from queue
							head.prepareOrder();
						    pq.poll();
						}
					}
				}
				// finished
                return;
            } catch (FileNotFoundException e) {
                // continue to next possible filename
            } catch (IOException e) {
            	// return any other exception
                System.out.println("Cannot read " + filename);
                return;
            }
		}
		// if no files were read, print this
		System.out.println("Input files do not exist");
	}
}
