int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
	int n = 0;
	while (graph[n]) n++;
	
	// Distance vector
	vector<int> dist(n, INT_MAX);
// 	vector<bool> visited(n, false);

    // Min heap pq to store (dist, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Init src
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            //check if there is an edge
            if (graph[u][v] > 0) {
                int weight = graph[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    return dist[dst];
}
