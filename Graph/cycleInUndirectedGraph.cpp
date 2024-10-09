/*
Using bfs or dfs
1) Check if any neighbor of a node other than the parent node is present in the visited array, if so, there is a cycle in the graph
2) Same process with bfs or dfs

T(C)- O(MXN)
S(C)- O(MXN)- Queue/Stack, Grid, vis
*/


class Solution {
  public:
    bool bfs(vector<int>adj[],int V,int s,vector<int>&vis){
        queue<pair<int,int>>st;
        st.push({s,-1});
        vis[s]=1;
        while(!st.empty()){
            int m=st.front().first,n=st.front().second;
            
            for(int i=0;i<adj[m].size();i++){
                if(vis[adj[m][i]]==1&&adj[m][i]!=n){
                    return true;
                }
                else if(vis[adj[m][i]]==-1){
                    st.push({adj[m][i],m});
                    vis[adj[m][i]]=1;
                }
            }
            st.pop();
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool res=false;
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1)
            res=res||bfs(adj,V,i,vis);
        }
        
        return res;
        // Code here
    }
};
