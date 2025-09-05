import java.util.ArrayList;
public class bs {

	public static void main(String[] args) {
		
		ArrayList<TestA> r = new ArrayList<TestA>();

		r.add( new TestA() );
		r.add( new TestB() );
		r.add( new TestC() );

		int sum = 0;
		for ( TestA t : r )
		  sum += t.p();

		System.out.println( sum ); 
	}
}

public class TestA
{
  public TestA()
  {
  }

  public int p()
  {
    return 1;
  }
}

public class TestB extends TestA
{
  public TestB()
  {
  }

  public int p()
  {
    return super.p() + 2;
  }
}

public class TestC extends TestB
{
  public TestC()
  {
  }
} 