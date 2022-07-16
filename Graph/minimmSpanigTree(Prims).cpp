// Ref Article-> https://takeuforward.org/data-structure/minimum-spanning-tree-mst-using-prims-algo/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 


	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    int parent[N];
    int key[N]; // containse weight of all the nodes
    bool mstSet[N]; 
    
    for(int i=0;i<N;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    // steps followed in Mst [Prims]
    // 1. pick the souce node and  check if its mstSet is true/false  if its false
    //    then check its weight wether its llest than our min weigth and add ito mstset and update min weight
    // 2. now mark mstSet of hat particular node as rue and check its adjacency list
    // 3. now check wether neighbouting nodes are in mstSet or not i and if there weight is less then
    //    weight stored in key array then update the key array and parent array
    for(int count=0;count<N-1;count++){
        int mini=INT_MAX,node;
        for(int i=0;i<N;i++){
            if(!mstSet[i] and key[i]<mini){
                mini=key[i];
                node=i;
            }
        }

        mstSet[node]=true;
        for(auto nbr:adj[node]{
            int v=nbr.first;
            int weight=nbr.second;
            if(!mstSet[v] and weight<key[v]){
                parent[v]=node;
                key[v]=weight;
            }
        })
    }

        for(int i=0;i<N;i++){
            cout<<"Edge "<<i<<"("<<parent[i]<<","<<i<<")"<<" weight="<<key[i]<<endl;
        }
    }