/*
THis method is correct when we have to find the shortest path between 
two nodes in an undirected graph with unit weight edges.

*/
vector<int>shortestPath(vector<int>adj[],int n,int source, int target){
    unordered_map<int,int>parent;
    vector<int>visited(n,0);
    queue<int>q;
    q.push(source);
    visited[source]=1;
    parent[source]=-1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto it :adj[front]){
            if(!visited[it]){
                visited[it]=1;
                parent[it]=front;
                q.push(it);
            }
        }
    }

    vector<int>path;
    int curr=target;
    while(curr!=source){
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    return path;
}