/*

Detect cycle in an undirected graph 
Medium Accuracy: 35.66% Submissions: 96148 Points: 4
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   

Output: 1
Explanation: 1->2->3->4->1 is a cycle.
Example 2:

Input: 

Output: 0
Explanation: No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
 

Constraints:
1 ≤ V, E ≤ 105

Company Tags

*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool cycle(int node,int parent, vector<int>&visit,vector<int>adj[]){
        
        visit[node]=1;
        
        // check for nabrs of the node
        for(auto nbr:adj[node]){
            
            if(!visit[nbr]){
                if(cycle(nbr,node,visit,adj))
                {return true;}
                
            }
            // agar nabr element is visited and is not parent
            // this tells that there is cycle
            else if(nbr!=parent) return true;
            
        }
        
        return false;
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>visit(V,0);

	    // check for all unconnected component
	    for(int i=0;i<V;i++){
	        if(!visit[i]){
	            if(cycle(i,-1,visit,adj)) return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends