void shortestPath(vector<int> adj[], int N, int src) {
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[u]+1<dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dist[i] << " ";
    }
}