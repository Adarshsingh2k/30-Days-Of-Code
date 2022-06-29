// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int source, vector<int>&res,
    vector<int>adj[], vector<int>&visited){
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto i: adj[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
    
    
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        // cout<<V;
        vector<int> res;
        // queue<int>q;
        // for(int i=0;i<V;i++){
        //     q.push()
        // }
        // for(int i=0;i<V;i++){
            
        //         // cout<<i;
        //         q.push(i);
        //         visited[i]=1;
        //         while(!q.empty()){
        //             int node=q.front();
        //             q.pop();
        //             res.push_back(node);
                    
        //             for(auto i:adj[node]){
        //                 if(!visited[i]){
        //                     q.push(i);
        //                     visited[i]=1;
        //                 }
        //             }
        //         }
            
        // }
        // // queue<int>q;
        
        // return res;
          bfs(0,res,adj,visited);
       return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends