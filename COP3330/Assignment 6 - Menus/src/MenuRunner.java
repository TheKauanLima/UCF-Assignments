/**
 * Kauan Lima
 * Assignment 6: Menus
 * COP 3330
 * 3/30/2025
 */
// all imports
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class MenuRunner {

	// main
	public static void main(String[] args) {
		// create new array list
		ArrayList<MenuItem> MIList = new ArrayList<MenuItem>();
		
		// read the file "menu.txt" line by line using buffered reader
		try (BufferedReader br = new BufferedReader(new FileReader("menu.txt"))) {
			// obtain the first line deatiling the number of objects to process
			String iter = (String)br.readLine();
			int numIter = Integer.parseInt(iter);
			
			// declare menuItem
			MenuItem mItem;
			
			// iterate through the previously specified # of lines
			for (int i = 0; i < numIter; i++) {
				// obtain the inputs by splitting at the delimiter ","
				String line = br.readLine();
				String regex = "[,]";
				
				String[] inputs = line.split(regex);
				double price = Double.parseDouble(inputs[2]);
				
				// create correct object type
				if (inputs[0].compareTo("Appetizer") == 0)
					mItem = new Appetizer(inputs[1], price);
				else if (inputs[0].compareTo("MainCourse") == 0)
					mItem = new MainCourse(inputs[1], price);
				else
					mItem = new Dessert(inputs[1], price);
				// add to array list
				MIList.add(mItem);
			}
			
			// sort list
			Collections.sort(MIList);
			
			// output each element
			System.out.println("Restaurant Menu:");
			for (MenuItem m : MIList) {
				System.out.printf("%s - %s: $%.2f\n", m.getType(), m.getName(), m.getPrice());
			}
		}
		// catch any and all errors
		catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
