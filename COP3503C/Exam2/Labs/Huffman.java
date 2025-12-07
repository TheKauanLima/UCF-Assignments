//COP3503
//Huffman.java
//Huffman Code

import java.util.PriorityQueue;
import java.util.Comparator;

class HuffmanNode 
{
	int item;
	char c;
	HuffmanNode left;
	HuffmanNode right;
}


class ImplementComparator implements Comparator<HuffmanNode> 
{
	public int compare(HuffmanNode x, HuffmanNode y) 
	{
		return x.item - y.item;
	}
}

public class Huffman 
{
	public static void printCode(HuffmanNode root, String s) 
	{
		if(root.left == null && root.right == null && Character.isLetter(root.c)) 
		{
			System.out.println(root.c + "   |  " + s);
			return;
		}
		
		printCode(root.left, s + "0");
		printCode(root.right, s + "1");
	}

	public static void main(String[] args) 
	{	
		PriorityQueue<HuffmanNode> q = new PriorityQueue<HuffmanNode>(args.length / 2, new ImplementComparator());

		for(int i = 0; i < args.length; i+=2) 
		{
			HuffmanNode hn = new HuffmanNode();

			hn.c = args[i].charAt(0);
			hn.item = Integer.parseInt(args[i + 1]);

			hn.left = null;
			hn.right = null;

			q.add(hn);
		}

		HuffmanNode root = null;

		while(q.size() > 1) 
		{
			HuffmanNode x = q.peek();
			q.poll();

			HuffmanNode y = q.peek();
			q.poll();
			
			HuffmanNode f = new HuffmanNode();
			
			f.item = x.item + y.item;
			f.c = '-';
			f.left = x;
			f.right = y;
			root = f;

			q.add(f);
		}
		
		System.out.println(" Char | Huffman code ");
		System.out.println("--------------------");
		printCode(root, "");
	}
}