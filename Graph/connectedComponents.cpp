/*Bfs approach
1) check adjacent elements via the adj matrix, by scanning the row, mark in the visited matrix
2) repeat until all the elements are traversed

T(C)- O(MXN)
S(C)- O(MXN) - adj matrix, visited array- O(N), queue
*/

class Solution {
  public:
    void bfs(vector<vector<int>>&adj, int V,vector<int>&vis,int m){
        queue<int>q;
        q.push(m);
        while(!q.empty()){
            q.push(-1);
            while(q.front()!=-1){
                int i=q.front();
                vis[i]=1;
                for(int k=0;k<V;k++){
                    if(adj[i][k]==1&&vis[k]==-1){
                        q.push(k);
                    }
                }
                q.pop();
            }
            q.pop();
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>vis(V,-1);
        int res=0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1&&vis[i]==-1){
                    bfs(adj,V,vis,i);
                    res++;
                }
            }
        }
        return res;
        // code here
    }
};
