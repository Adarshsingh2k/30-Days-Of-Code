class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool cycle(int node,int parent, vector<int>&visit,vector<int>adj[]){
        
        visit[node]=1;
        
        for(auto nbr:adj[node]){
            
            if(!visit[nbr]){
                if(cycle(nbr,node,visit,adj))
                {return true;}
                
            }
            else if(nbr!=parent) return true;
            
        }
        
        return false;
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>visit(V+1,0);
	    for(int i=0;i<V;i++){
	        if(!visit[i]){
	            if(cycle(i,-1,visit,adj)) return true;
	        }
	    }
	    return false;
	}
};