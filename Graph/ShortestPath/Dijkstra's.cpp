/*
 Given a weighted, undirected, connected graph, that may contain cycles, find the shortest path from source to all the nodes in the graph

Since, there are cycles, it is not possible to determine which node comes first in an undirected graph, so topo sort only works for directed graphs

This can be solved using 3 approaches, Queue, Priority Queue, and Set, 
  QUeue - T(C)- O(VXE), S(C)- O(VXE)
  Pq, and set depending on the context have their own benefits, from the set we can remove the same vertex with higher path cost present in the set by trading the o(log(heapsize))
both these approaches can be used
T(C)- O(Elog V) S(C)- O(v) where E=v^2 in the worst case

*/

class Solution{
    public:
    vector<int> dijkstra(vector<vector<pair<int,int>>>&adj,int src){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            int v=adj.size();
            vector<int>mincost(v,INT_MAX);
            pq.push({0,src});
            mincost[src]=0;
            while(!pq.empty()){
                   int cur=pq.top().second,pathcost=pq.top().first;
                   pq.pop();
                    for(auto neighbour:adj[cur]){
                    int node=neighbour.first,weight=neighbour.second;
                    if(mincost[node]>weight+pathcost){
                            mincost[node]=weight+pathcost;
                            pq.push({mincost[node],node});
                    }
                }
                    
            }
            return mincost;
    }
};
