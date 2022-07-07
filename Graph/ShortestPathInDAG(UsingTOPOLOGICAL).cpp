#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        // Directed weighted graph
        unordered_map<int,list<pair<int,int>>>adj;

        void addEdge(int u,int v,int w){
            adj[u].push_back(make_pair(v,w));
        }

        void printGraph(){
            for(auto it:adj){
                cout<<it.first<<"->";
                for(auto it1:it.second){
                    cout<<"("<<it1.first<<","<<it1.second<<")"<<" ";
                }
                cout<<endl;
            }
        }

        void dfs(int node, unordered_map<int,bool>&vis,stack<int>&topo){
            vis[node]=true;
           for(auto i:adj[node]){
            if(!vis[i.first]) dfs(i.first,vis,topo);
           }
           topo push(node);

        }

        void getShortestPath(int src,vector<int>&dist,stack<int>&topo){
            
            dist[src]=0;
            while(!topo.empty()){
                int top=topo.top();
                topo.pop();
                if(dist[top]!=INT_MAX){
                    for(auto i :adj[top]){
                        if(dist[top]+i.second<dist[i.first]){
                            dist[i.first]=dist[top]+i.second;
                        }
                    }
                }
            }

        }


};

int main(){

    Graph g;
    g.addEdge(0,1,10);
    g.addEdge(0,2,10);
    g.addEdge(1,2,10);
    g.addEdge(2,3,10);  
    g.addEdge(3,4,10);
    
    g.printGraph();
    unordered_map<int,bool>vis;
    stack<int>topo;
    int n=6; // no of nodes
    for(int i=0;i<n;i++){
        if(!vis[i]) g.dfs(i,vis,topo);
    }

    int src=1; // assuming source node to be 1 from where we have to find the distance
    vector<int>dist(n,INT_MAX);
    g.getShortestPath(src,dist,topo);
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    
}