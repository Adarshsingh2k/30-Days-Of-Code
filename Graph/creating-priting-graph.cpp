#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
      unordered_map<int,list<int>> adj;

      void addEdge(int u, int v,bool direction){
        adj[u].push_back(v);

        // if undirected graph
        if(direction==false){
          adj[v].push_back(u);
        }

      }

      void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
      }

};

int main(){
    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter edge: ";
        cin>>u>>v;
        g.addEdge(u,v,false);
    }

    g.print();


}