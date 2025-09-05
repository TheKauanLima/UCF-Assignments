/**
 * Purpose: create a "Pets" class to gather information to use in the "PetsTester" class.
 * 
 * @author Kauan Lima
 * @version 12/1/2023
 */
public class PetsV3
{
	//declare instance variables for pet name, pet breed and pet age
	private String name;
	private String breed;
	private int age;
	
	//create the default constructor
	public PetsV3()
	{
		
	}
	
	//create the constructor with parameters
	public PetsV3(String n, String b, int a)
	{
		name = n;
		breed = b;
		age = a;
	}
	//setter & getter methods for petName, petBreed and petAge
	public String getName()
	{
		return name;
	}
	
	public String getBreed()
	{
		return breed;
	}
	
	public int getAge()
	{
		return age;
	}
	
	public void setName(String newName)
	{
		name = newName;
	}
	
	public void setBreed(String newBreed)
	{
		breed = newBreed;
	}
	
	public void setAge(int newAge)
	{
		age = newAge;
	}
}