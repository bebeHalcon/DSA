class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions
    //DFS
    void topoHelper(int v, bool* visited, stack<int>& st)
    {
        visited[v] = true;
        
        int n = adj[v].getSize();
        for (int i = 0; i < n; i++)
        {
            int temp = adj[v].getElement(i);
            if (!visited[temp])
                topoHelper(temp, visited, st);
        }
        st.push(v);
    }
    
    void topologicalSort(){
        //TODO
        stack <int> st;
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;
            
        for (int i = 0; i < V; i++){
            if (visited[i] == false){
                topoHelper(i, visited, st);
            }
        }
        
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        delete [] visited;
    }
};