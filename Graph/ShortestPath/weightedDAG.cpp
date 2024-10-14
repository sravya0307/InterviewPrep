/*
Given a directed acyclic Graph with different weights on each of the edges, find the shortest distance from 0 the vertex to all the vertices
1) BFS approach can be used, but instead of tracking the visited nodes and refraining to visit them again, we can instead check if the cost of path traversed earlier
is more than current cost, if so replace with current cost
2) We would traverse the entire graph, all the paths in this approach

T(C)- O(V+E)
S(C)- O(V+E)- adjlist, v-res

*/

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int,int>>>adj(N,vector<pair<int,int>>());
         for(int i=0;i<M;i++){
             adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         }
         vector<int>res(N,-1);
         queue<pair<int,int>>q;
         q.push({0,0});
         res[0]=0;
         while(!q.empty()){
             q.push({-1,-1});
             while(q.front().first!=-1){
                 int a=q.front().first,b=q.front().second;
                 for(int i=0;i<adj[a].size();i++){
                     if((res[adj[a][i].first]>b+adj[a][i].second)||res[adj[a][i].first]==-1){
                         q.push({adj[a][i].first,b+adj[a][i].second});
                         res[adj[a][i].first]=b+adj[a][i].second;
                     }
                 }
                 q.pop();
             }
             q.pop();
         }
         return res;
    }
};

