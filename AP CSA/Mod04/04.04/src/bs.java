
public class bs {

	public static void main(String[] args) {
		int maxitems = 5;
	    int value = 5;
	    int[] a = new int[ maxitems ];
	    int total = 0;

	    a[0] = 4;
	    a[1] = 4;
	    a[2] = 4;
	    a[3] = 4;
	    a[4] = 4;

	    int index;

	    for ( index = 0 ; index < maxitems ; index++ )
	    {
	      if ( a[ index ] < value )
	        total++;
	    }

	    System.out.println(total);
	}

}
