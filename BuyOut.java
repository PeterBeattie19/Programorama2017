import java.util.*; 
import java.io.*; 

public class BuyOut {
	public static void main (String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 

		ArrayList<LinkedList<Edge>> graph = new ArrayList<>(); 

		//Each index in the array list is a node in the graph
		//Stored in each index is a linked list of Edges, each edge has a weight(int) and a destination(int)
		//For Example: graph[2]: Edge(3,5) -> Edge(4,7) , this means nodes number 2 is connected to two other nodes,
		//it connects to node 2 with a weight of 5 and node 4 with a weight of 7


		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(new Comparator<Edge> (){
        	public int compare(Edge x, Edge y){
            	if(x.weight == y.weight) return 0; 

            	return x.weight - y.weight; 
        	} 
		}); 

		


		String line[] = br.readLine().split(" "); 

		int numNodes = Integer.parseInt(line[0]); 
		int numConnections = Integer.parseInt(line[1]);

		for(int i = 0; i<=numNodes; i++){
			graph.add(new LinkedList<Edge>()); 
		}

		line = br.readLine().split(" "); 

		for(int i = 0; i<numNodes; i++){
			graph.get(0).add(new Edge(i+1 , Integer.parseInt(line[i])));
		}

		for(int i = 1; i<=numConnections; i++){
			line = br.readLine().split(" "); 
			int a = Integer.parseInt(line[0]) + 1;
			int b = Integer.parseInt(line[1]) + 1;

			graph.get(a).add(new Edge(b,0)); 
			graph.get(b).add(new Edge(a,0)); //Remove this line if graph is directed 
		}

		//Calculate Minimum Spanning Tree

		HashSet<Integer> visited = new HashSet<>();
		visited.add(0); 
		int currentNode = 0; 
		int result = 0; 


		while(visited.size() != numNodes+1){
			addAdj(currentNode, graph, pq); 
			Edge add = null; 

			while(true){
				add = pq.poll();
				if(visited.add(add.destination) == true) break;  
			}

			//System.out.println(add.weight); 
			result += add.weight; 
			currentNode = add.destination; 

		}

		System.out.println(result);
	}

	public static class Edge{
		int destination;
		int weight; 

		public Edge(int d, int w){
			destination = d; 
			weight = w; 
		}
	}

	public static void addAdj(int i, ArrayList<LinkedList<Edge>> graph, PriorityQueue<Edge> pq){
		for(Edge e: graph.get(i)) pq.add(e); 
	}

} 