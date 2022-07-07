void dijkstras(int src,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq,vector<int>&dist){
    // initially distance of all nodes should be INT_MAX
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int dis=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        
            for(auto i :adj[prev]){
              int next=i.first;
              int nextDist=i.second;
              if(dist[next]>dist[prev]+nextDist){
                  dist[next]=dist[prev]+nextDist;
                  pq.push(make_pair(dist[next],next));
              }
            }
        
    }
}