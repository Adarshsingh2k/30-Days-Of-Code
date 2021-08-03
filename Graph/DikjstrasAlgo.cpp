/*
Implementing Dijkstra Algorithm 
Medium Accuracy: 49.0% Submissions: 40314 Points: 4
Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes number of vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 .<? g.hg,./  lb/n.,k
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        vector <int >dist(v,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        
        
        dist[s]=0;
        
        vector<bool>vis(v+1,false);
        pq.push(make_pair(0,s));
        
        while(!pq.empty()){
            
            //int d=pq.top().first;
            
            
             int p = pq.top().second;
            pq.pop();
            
            for(auto j:adj[p]){
                
                int node = j[0];
                int w = j[1];
                if( w+dist[p]<dist[node]){
                    dist[node] = w+dist[p];
                    pq.push({dist[node],node});
                }
            }
        }
        
        
        return dist;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends

/*//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,source;
    cin >> n >> m;
    vector<pair<int,int> > g[n+1];  // 1-indexed adjacency list for of graph

    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }   
    
    cin >> source;
    
    // Dijkstra's algorithm begins from here
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
    vector<int> distTo(n+1,INT_MAX);    // 1-indexed array for calculating shortest paths; 
    
    distTo[source] = 0;
    pq.push(make_pair(0,source));   // (dist,from)
    
    while( !pq.empty() ){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        
        vector<pair<int,int> >::iterator it;
        for( it = g[prev].begin() ; it != g[prev].end() ; it++){
            int next = it->first;
            int nextDist = it->second;
            if( distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
        
    }
    
    cout << "The distances from source, " << source << ", are : \n";
    for(int i = 1 ; i<=n ; i++) cout << distTo[i] << " ";
    cout << "\n";
    
    return 0;

*/