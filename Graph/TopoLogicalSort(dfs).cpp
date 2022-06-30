class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfsTopo(int node,vector<int>&vis,stack<int>&s,vector<int> adj[] ){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it]) dfsTopo(it,vis,s,adj);
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>s;
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfsTopo(i,vis,s,adj);
	        }
	    }
	    vector<int>out;
	    while(!s.empty()){
	        out.push_back(s.top());
	        s.pop();
	    }
	    return out;
	    
	}
};
