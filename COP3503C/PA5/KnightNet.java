/* Kauan Lima
   Dr. Steinberg
   COP3503 Fall 2025
   Programming Assignment 5
*/

import java.io.*;
import java.util.*;

public class KnightNet
{
    // private instance variables
    private HashSet<String> nodes;
    private HashSet<String> decoys;
    private HashMap<String, ArrayList<Edge>> adj;
    private ArrayList<MSTEdge> mstEdges;

    // private classes
    private static class Edge
    {
        String target;
        int weight;
        int visibility;
        
        Edge(String target, int weight, int visibility)
        {
            this.target = target;
            this.weight = weight;
            this.visibility = visibility;
        }
    }

    private static class PrimEdge
    {
        int targetIndex;
        int weight;
        int visibility;

        PrimEdge(int targetIndex, int weight, int visibility)
        {
            this.targetIndex = targetIndex;
            this.weight = weight;
            this.visibility = visibility;
        }
    }

    private static class Vertex implements Comparable<Vertex>
    {
        int id;
        int key; // minimum weight edge connecting this vertex to the MST
        int parent; // predecessor in MST
        int visibility;

        Vertex(int id, int key)
        {
            this.id = id;
            this.key = key;
            this.parent = -1;
            this.visibility = 0;
        }

        @Override
        public int compareTo(Vertex other)
        {
            return Integer.compare(this.key, other.key);
        }
    }

    private static class MSTEdge
    {
        String nodeA;
        String nodeB;
        int cost;
        int visibility;

        MSTEdge(String nodeA, String nodeB, int cost, int visibility)
        {
            this.nodeA = nodeA;
            this.nodeB = nodeB;
            this.cost = cost;
            this.visibility = visibility;
        }
    }

    // constructor
    public KnightNet(String filename, int maxVisibility)
    {
        // initialize instance variables
        nodes = new HashSet<>();
        decoys = new HashSet<>();
        adj = new HashMap<>();
        mstEdges = new ArrayList<>();

        // read file line by line
        try (BufferedReader br = new BufferedReader(new FileReader(filename)))
        {
            String ln;
            while ((ln = br.readLine()) != null)
            {
                // trim and split into tokens
                ln = ln.trim();
                String[] tokens = ln.split(",");

                // add to appropriate values
                String a = tokens[0].trim();
                String b = tokens[1].trim();
                int cost = Integer.parseInt(tokens[2].trim());
                int vis = Integer.parseInt(tokens[3].trim());
                boolean isDecoy = Boolean.parseBoolean(tokens[4].trim());

                // add nodes
                nodes.add(a);
                nodes.add(b);

                // add decoys
                if (isDecoy)
                {
                    decoys.add(a);
                    decoys.add(b);
                }

                // skip decoys for adjacents
                if (isDecoy)
                    continue;
                if (decoys.contains(a) || decoys.contains(b))
                    continue;

                // add adjacents
                addAdj(a, b, cost, vis);
                addAdj(b, a, cost, vis);
            }
        }
        // exception handling
        catch (IOException ex)
        {
            throw new RuntimeException("IO error: " + ex);
        }
    }

    private void addAdj(String from, String to, int cost, int vis)
    {
        ArrayList<Edge> list = adj.get(from);
        
        // create new arraylist if from is null
        if (list == null)
        {
            list = new ArrayList<>();
            adj.put(from, list);
        }

        list.add(new Edge(to, cost, vis));
    }

    public HashSet<String> getRealNodes()
    {
        HashSet<String> r = new HashSet<>();

        // add all nodes to r which are not decoys
        for (String n : nodes)
            if (!decoys.contains(n))
                r.add(n);

        return r;
    }

    public int computeMSTCost(String startNode, int maxVisibility)
    {
        // cleanup and find real nodes
        mstEdges.clear();
        HashSet<String> real = getRealNodes();
        if (!real.contains(startNode) || real.size() <= 1)
            return 0;

        // collect and sort all real nodes
        ArrayList<String> nodeList = new ArrayList<>(real);
        Collections.sort(
            nodeList,
            new Comparator<String>()
            {
                public int compare(String a, String b)
                {
                    return Integer.compare(nodeNumber(a), nodeNumber(b));
                }
            }
        );

        // assign each node to an index
        int n = nodeList.size();
        HashMap<String,Integer> index = new HashMap<>();
        for (int i = 0; i < n; i++)
            index.put(nodeList.get(i), i);

        // Create list of lists of PrimEdge.
        ArrayList<ArrayList<PrimEdge>> primAdj = new ArrayList<>();
        for (int i = 0; i < n; i++)
            primAdj.add(new ArrayList<PrimEdge>()); // different list for each adjacent node

        // iterate through each node
        for (int i = 0; i < n; i++)
        {
            String nodeID = nodeList.get(i);
            ArrayList<Edge> list = adj.get(nodeID);
            if (list == null)
                continue;

            // add lists for each index in primAdj with each adjacent node
            for (Edge e : list)
            {
                if (e.visibility > maxVisibility)
                    continue;

                // find node index and store in primEdge list
                Integer targetIndex = index.get(e.target);
                if (targetIndex == null)
                    continue;

                primAdj.get(i).add(new PrimEdge(targetIndex, e.weight, e.visibility));
            }
        }

        // setup arrays and infinite vertex values
        int start = index.get(startNode);
        boolean[] inMST = new boolean[n];
        Vertex[] vertexes = new Vertex[n];
        for (int i = 0; i < n; i++)
            vertexes[i] = new Vertex(i, Integer.MAX_VALUE);

        // set start to 0
        vertexes[start].key = 0;

        // add vertexes to a priority queue
        PriorityQueue<Vertex> pq = new PriorityQueue<>();
        pq.addAll(Arrays.asList(vertexes));

        // iterate for each vertex
        while (!pq.isEmpty())
        {
            //Extract the vertex with minimum key value
            Vertex node = pq.poll();
            inMST[node.id] = true;

            //For each adjacent vertex adjacentNode of node
            for (PrimEdge primEdge : primAdj.get(node.id))
            {
                // extra variables for improved readability
                int adjacentNode = primEdge.targetIndex;
                int weight = primEdge.weight;
                int vis = primEdge.visibility;

                // if adjacentNode is not in MST and weight(node, adjacentNode) < key[adjacentNode]
                if (!inMST[adjacentNode] && weight < vertexes[adjacentNode].key)
                {
                    // decrease key of adjacentNode
                    pq.remove(vertexes[adjacentNode]);
                    vertexes[adjacentNode].key = weight;
                    vertexes[adjacentNode].parent = node.id;
                    vertexes[adjacentNode].visibility = vis;
                    pq.add(vertexes[adjacentNode]);
                }
            }
        }

        // calculate total cost
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            // check if node has a value and predecessor
            if (vertexes[i].parent != -1 && vertexes[i].key < Integer.MAX_VALUE)
            {
                // get nodes and swap if a bigger than b
                String nodeA = nodeList.get(vertexes[i].parent);
                String nodeB = nodeList.get(i);
                if (nodeNumber(nodeA) > nodeNumber(nodeB))
                {
                    String tmp = nodeA;
                    nodeA = nodeB;
                    nodeB = tmp;
                }

                // add new edge to display later, and update total
                mstEdges.add(new MSTEdge(nodeA, nodeB, vertexes[i].key, vertexes[i].visibility));
                total += vertexes[i].key;
            }
        }

        return total;
    }

    public void displayEdges()
    {
        // sort mstedges from smallest to largest first
        Collections.sort(
            mstEdges,
            new Comparator<MSTEdge>()
            {
                public int compare(MSTEdge edge1, MSTEdge edge2)
                {
                    int u1 = nodeNumber(edge1.nodeA);
                    int u2 = nodeNumber(edge2.nodeA);

                    if (u1 != u2)
                        return u1 - u2;

                    int v1 = nodeNumber(edge1.nodeB);
                    int v2 = nodeNumber(edge2.nodeB);

                    return v1 - v2;
                }
            }
        );

        // print MST edges
        for (MSTEdge e : mstEdges)
            System.out.println(e.nodeA + " - " + e.nodeB +
                               " | Cost: " + e.cost +
                               " | Visibility: " + e.visibility);
    }

    public void removeNode(String node)
    {
        if (!nodes.contains(node))
            return;

        // remove specified node from all lists
        nodes.remove(node);
        decoys.remove(node);
        adj.remove(node);
        for (Map.Entry<String, ArrayList<Edge>> entry : adj.entrySet())
        {
            ArrayList<Edge> list = entry.getValue();

            if (list == null)
                continue;

            list.removeIf(e -> e.target.equals(node));
        }
    }

    // return number associated with nodeID
    private int nodeNumber(String nodeID)
    {
        return Integer.parseInt(nodeID.substring(1));
    }
}