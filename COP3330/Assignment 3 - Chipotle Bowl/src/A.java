
public class A {
	private int x = 3;
	private int[] arr;
	
	public A(int x) {
		this.x = x;
		arr = new int[3];
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
	}
	
	public int GetX() {
		return arr[1];
	}
	
	public String ToString() {
		return "A: " + GetX() + " " + x;
	}
}

class B extends A {
	private int x = 5;
	private int[] arr;
	
	public B(int x) {
		super(x * 2);
		this.x = x;
		arr = new int[3];
		arr[0] = 4;
		arr[1] = 5;
		arr[2] = 6;
	}
	
	public int GetX() {
		return super.GetX() + 2;
	}
	
	public String ToString() {
		return String.valueOf(x);
	}
}

class C extends A {
	private int x = 3;
	private int[] arr;
	
	public C(int x) {
		super(x / 2);
		this.x = x;
	}
	
	public int GetX() {
		super.GetX();
		return x;
	}
	
	public String ToString() {
		return super.ToString();
	}
}