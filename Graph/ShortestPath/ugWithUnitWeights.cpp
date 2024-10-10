/*
Given an undirected graph with unit weights on the edges, and a source node, calculate shortest distance from source to all the nodes
1) This can be done using simple Bfs approach by tracking the current level and marking the ones that cannot be reached with -1
  T(C)-O(V+E)
  S(C)-O(V+E)- adjlist, V-Queue
*/

class Solution {
  public:
    void adjlist(vector<vector<int>>&edges,int M,vector<vector<int>>&adj){
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    void bfs(vector<vector<int>>&adj,int N,int src,vector<int>&res){
        
        vector<int>vis(N,-1);
        queue<int>q;
        q.push(src);
        vis[src]=1;
        int c=0;
        while(!q.empty()){
            q.push(-1);
            while(q.front()!=-1){
                res[q.front()]=c;
                for(int i=0;i<adj[q.front()].size();i++){
                    if(vis[adj[q.front()][i]]==-1){
                        vis[adj[q.front()][i]]=1;
                        q.push(adj[q.front()][i]);
                    }
                }
                q.pop();
            }
            c++;
            q.pop();
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>>adj(N,vector<int>());
        adjlist(edges,M,adj);
        vector<int>res(N,-1);
        bfs(adj,N,src,res);
        return res;
    }
};
