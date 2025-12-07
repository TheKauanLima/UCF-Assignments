/*  Kauan Lima
    Dr. Steinberg
    COP3503 Fall 2025
    Programming Assignment 3
*/

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

// setup huffman node
class HuffmanNode
{
    int freq;
    String s;
    HuffmanNode left;
    HuffmanNode right;
}

// compare item values properly
class ImplementComparator implements Comparator<HuffmanNode>
{
    public int compare(HuffmanNode x, HuffmanNode y)
    {
        return x.freq - y.freq;
    }
}

public class NetworkPacket
{
    // instance variables
    private final Map<String, Integer> freq = new HashMap<>();
    private final Map<String, String> code = new HashMap<>();
    
    public void analyzeFrequencies(ArrayList<String> symbols)
    {
        freq.clear();

        // with each symbol, count its occurrences
        for(String s : symbols)
        {
            freq.put(s, freq.getOrDefault(s, 0) + 1);
        }
    }

    public void buildHuffmanTree()
    {
        // don't create tree if freq is empty
        if (freq.isEmpty())
            return;

        // create new pq of size freq
        PriorityQueue<HuffmanNode> q =
        new PriorityQueue<>(freq.size(), new ImplementComparator());

        // create huffman nodes and add to pq
        for (var entry : freq.entrySet()) {
            HuffmanNode node = new HuffmanNode();
            node.s = entry.getKey();
            node.freq = entry.getValue();
            node.left = node.right = null;
            q.add(node);
        }

        // construct huffman tree
        HuffmanNode root = null;
        while (q.size() > 1) {
            HuffmanNode x = q.peek();
            q.poll();
            HuffmanNode y = q.peek();
            q.poll();

            HuffmanNode front = new HuffmanNode();
            front.freq = x.freq + y.freq;
            front.s = null;
            front.left = x;
            front.right = y;
            root = front;
            q.add(front);
        }
        code.clear();
        buildCodes(root, "");
    }

    private void buildCodes(HuffmanNode root, String bitString)
    {
        // if leaf, assign bitString to symbol
        if (root.left == null && root.right == null && root.s != null) {
            code.put(root.s, bitString.length() == 0 ? "0" : bitString);
            return;
        }

        // traverse the tree and create code
        buildCodes(root.left,  bitString + "0");
        buildCodes(root.right, bitString + "1");
    }

    public String encode(ArrayList<String> symbols)
    {
        StringBuilder sb = new StringBuilder();

        // for each symbol in file, append bits
        for (String s : symbols) {
            String bits = code.get(s);
            sb.append(bits);
        }
        return sb.toString();
    }

    public double getHuffmanAvg(ArrayList<String> symbols)
    {
        int totalBits = 0;

        // for each symbol in freq
        for (Map.Entry<String,Integer> e : freq.entrySet())
        {
            // obtain its count and bitString
            String sym = e.getKey();
            int count = e.getValue();
            String bits = code.get(sym);
            totalBits += (long) count * bits.length();
        }

        // divide totalBits by symbols in file
        return (double) totalBits / symbols.size();
    }

    public double getRatio(double huffmanAvg)
    {
        // determine # of unique symbols
        int unique = freq.size();
        double bitsPerSymbol = Math.ceil(Math.log(unique) / Math.log(2)); // Math.ceil to round up
        return bitsPerSymbol / huffmanAvg;
    }
}
