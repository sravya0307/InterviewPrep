/*
Given a directed acyclic Graph with different weights on each of the edges, find the shortest distance from 0 the vertex to all the vertices
1) BFS approach can be used, but instead of tracking the visited nodes and refraining to visit them again, we can instead check if the cost of path traversed earlier
is more than current cost, if so replace with current cost
2) We would traverse the entire graph, all the paths in this approach
But this approach would take 
T(C)- O(VXE)
S(C)- O(VXE)- adjlist, v-res

Since this a DAG, and to calculate a cost path up until node, we require the min costpaths from all of it's parents. Hence, all the nodes that come before the current node
  must be traversed. To make this happen, topological sort can be used. Track the minimum cost path with the help of a vector along with indegree.

  T(C)- O(V+E)
  S(C)- O(V+E)

  */
class Solution{
     public:
       void create_adj_list(int E,vector<vector<int>>&edges,vector<vector<pair<int,int>>>&adj_list){
                 for(int i=0;i<E;i++){
                     adj_list[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                }
}
 void calculate_indeg(int V,vector<vector<pair<int,int>>>&adj_list,vector<int>&indeg){
              for(int i=0;i<V;i++){
                   for(int j=0;j<adj_list[i].size();j++){
                      indeg[adj_list[i][j].first]++;
                   }
              }
 }
 void remove_zero_indeg(vector<int>&indeg,vector<vector<pair<int,int>>>&adj_list,int V){
     for(int i=1;i<V;i++){
          if(indeg[i]==0){
              for(int j=0;j<adj_list[i].size();j++){
                  indeg[adj_list[i][j].first]--;
              }
          }
     }
 }
vector<int> topo_sort(vector<vector<pair<int,int>>>&adj_list,vector<int>&indeg,int V,int E){
         queue<pair<int,int>>q;
         vector<int>res(V,-1);
         vector<int>mincost(V,INT_MAX);
         q.push({0,0});
         while(!q.empty()){
              int node=q.front().first,pathcost=q.front().second;
              res[node]=pathcost;
              for(int i=0;i<adj_list[node].size();i++){
                int a=adj_list[node][i].first,b=adj_list[node][i].second;
                   indeg[a]--;
                   mincost[a]=min(mincost[a],pathcost+b);
                   if(indeg[a]==0){
                       q.push({a,mincost[a]});
                   }
              }
              q.pop();
         }
return res;
}
     vector<int> shortestPath(int V,int E,vector<vector<int>>&edges){
              vector<vector<pair<int,int>>>adj_list(V,vector<pair<int,int>>());
               create_adj_list(E,edges,adj_list);
               vector<int>indeg(V,0);
               calculate_indeg(V,adj_list,indeg);
               remove_zero_indeg(indeg,adj_list,V);
              return topo_sort(adj_list,indeg,V,E);
     }
};




