
class Solution {
public:
	//DFS recursive function
    void DFS_rec(vector<int> adj[],int s,bool visited[],vector<int> vec){
        if(visited[s]==true){return;}
    visited[s] = true;
    cout<<s<<" ";
    vec.push_back(s);
    for(int x: adj[s]){
        if(visited[x]==false){
            DFS_rec(adj,x,visited,vec);
        }
    }
    }
    
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	  bool visited[V];
	  for(int i=0;i<V;i++){ visited[i]=false;}
	  vector<int> vec;
	  for(int i=0;i<V;i++){
	  DFS_rec(adj,i,visited,vec);}
	  return vec;
	}
};