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
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        Adjacency *res = new Adjacency;
        // v is a vertex we start BFS
        bool visited[V];
        for (int i=0; i<V; i++)
            visited[i] = false;
            
        list <int> q;
        visited[v] = true;
        q.push_back(v);
        // res -> push(v);
     
        while(!q.empty())
        {
            int s = q.front();
            res -> push(s);
            q.pop_front();
            int n = adj[s].getSize();
            
            for (int i=0; i<n; i++)
            {
                int temp = adj[s].getElement(i);
                if (!visited[temp])
                {
                    visited[temp] = true;
                    q.push_back(temp);
                }
            }
        }
        return res;
	}
};