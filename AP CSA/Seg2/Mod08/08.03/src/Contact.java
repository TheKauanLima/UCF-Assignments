/**
 * @purpose: Contacts class to use in the ContactsTester class as an object.
 * 
 * @author Kauan Lima
 * @version 3/10/2024
 */
public class Contact
{
	private String name;
	private String relation;
	private String birthday;
	private String phoneNumber;
	private String emailAddress;
	
	public Contact(String n, String r, String b, String p, String e)
	{
		name = n;
		relation = r;
		birthday = b;
		phoneNumber = p;
		emailAddress = e;
	}
	
	public String getName()
	{
		return name;
	}
	
	public String getRelation()
	{
		return relation;
	}
	
	public String getBirthday()
	{
		return birthday;
	}
	
	public String getPhoneNumber()
	{
		return phoneNumber;
	}
	
	public String getEmailAddress()
	{
		return emailAddress;
	}
	
	public void setName(String n)
	{
		name = n;
	}
	
	public void setRelation(String r)
	{
		relation = r;
	}
	
	public void setBirthday(String b)
	{
		birthday = b;
	}
	
	public void setPhoneNumber(String p)
	{
		phoneNumber = p;
	}
	
	public void setEmailAddress(String e)
	{
		emailAddress = e;
	}
	
	public String toString()
    {
        String str = String.format( "%-18s %-22s %-23s %-25s %-26s", name,  relation, birthday, phoneNumber, emailAddress);
        return str;
    }
}
