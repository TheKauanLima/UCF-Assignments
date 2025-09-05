import java.util.Scanner;
public class A1Runner {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Welcome to Knightro's Pizza");
		System.out.println("How big of a pizza are we making?");
		
		Pizza p = new Pizza(scan.nextInt());
		
		System.out.println("Describing the pizza: " + p.describePizza());
		System.out.printf("The area of this pizza is: %.4f\n",
		p.areaPerSlice());
		
		System.out.println("How many slices should we cut it into?");
		p.setSlices(scan.nextInt());
		
		System.out.printf("The area of each slice is: %.4f\n",
		p.areaPerSlice());
		p.displaySlices();
	}
}