//  Kahns Algo-> Concept of indegree
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   queue<int>q;
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	       for(auto it:adj[i]) indegree[it]++;
	    }
	    // populate queue with elements hving indegree==0
	    for(int i=0;i<V;i++)if(indegree[i]==0)q.push(i);
	   
	    vector<int>out;
	   //  Apply bfs -> decrement indegree for al elements adjacent to current node element
	   // if indgree == 0 push to queue
	   // push the present node element to output vector to get TOP SORT
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        out.push_back(node);
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    return out;
	    
	}
};