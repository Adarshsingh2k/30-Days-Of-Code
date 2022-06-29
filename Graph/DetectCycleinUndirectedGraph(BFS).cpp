class Solution {
  public:
    bool cycle(int V, vector<int> adj[],vector<int>&visited, int s){
        queue<pair<int,int>>q;
        
        visited[s]=true;
        q.push({s,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent= q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,node});
                }
                else if (parent!=it){
                    return true;
                    
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V ;i++){
            if(!visited[i]){
                if (cycle(V,adj,visited,i)) return true;
            }
        }
        return false;
    }
};