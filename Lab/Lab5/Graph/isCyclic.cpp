#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int> > adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int> >(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	
	bool isCyclicHelper(int v, vector<bool>& visited, vector<bool>& recStack){
    	// Mark the current node as visited and add it to the recursion stack
        visited[v] = true;
        recStack[v] = true;
    
        // Explore all neighbors
        for (int neighbor : adj[v]) {
            // If the neighbor is not visited, recur for that neighbor
            if (!visited[neighbor] && isCyclicHelper(neighbor, visited, recStack))
                return true;
            // If the neighbor is in the recursion stack, we found a cycle
            else if (recStack[neighbor])
                return true;
        }

    // Remove the current node from the recursion stack
    recStack[v] = false;
    return false;
    }
    
	bool isCyclic()
	{
	    // Student answer
	    vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // Call the helper function for all vertices to check for cycles
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicHelper(i, visited, recStack))
                    return true;
            }
        }
        return false;
	}
}; 

int main(){

    DirectedGraph g(8); 
    int edege[][2] = {{0,6}, {1,2}, {1,4}, {1,6}, {3,0}, {3,4}, {5,1}, {7,0}, {7,1}};

    for(int i = 0; i < 9; i++)
        g.addEdge(edege[i][0], edege[i][1]);

    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle";
}