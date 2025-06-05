class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	void DFSHelp(int v, Adjacency* res, bool *visited) 
	{
	    visited[v] = true;
        res -> push(v);
        
        int n = adj[v].getSize();
        for (int i=0; i<n; i++)
        {
            int temp = adj[v].getElement(i);
            if (!visited[temp])
                DFSHelp(temp, res, visited);
        }
	}
	
	Adjacency *DFS(int v)
    {
        Adjacency* res = new Adjacency;
        // v is a vertex we start DFS
        
        bool *visited = new bool[V];
        for (int i=0; i<V; i++)
            visited[i] = false;
            
        DFSHelp(v, res, visited);
        return res;
	}
};