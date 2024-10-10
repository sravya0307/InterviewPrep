/*
Given a alien dictionary, where the order of alphabets is not of the generic one, but a different one, according to the words provided in the dictionary,
  return the order of alphabets.

EX: n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
  res='b', 'd', 'a', 'c' 
1) To understand the order of alphabets we can compare the first different letters in the adjacent words, and the one that comes first, also comes before in the alphabetical order, 
ex- by comparing "baa", "abcd", it can be understood b comes before a, similarly by comparing "abcd" and "abca" it can be understood d comes before a, so by this an adjacency list
can be created.
2) Now, it is simple by performing topological sort, the order of alphabets can be obtained, since that is what topo sort does, providing an order such that for u->v u comes
before v using dfs+track stack

T(C)- O(n*max size of string)+O(V+E) where V is k
S(C)- O(V+E)- adjlist, O(k)-track stack, res-O(k)
*/

class Solution {
  public:
   void dfs(stack<int>&track,vector<int>&vis,vector<vector<int>>&adj,int cur){
       
       for(int i=0;i<adj[cur].size();i++){
           if(vis[adj[cur][i]]==-1){
               vis[adj[cur][i]]=1;
               dfs(track,vis,adj,adj[cur][i]);
           }
       }
       track.push(cur);
   }
    string findOrder(string dict[], int n, int k) {
        vector<vector<int>>adj(26,vector<int>());
        for(int i=0;i<n-1;i++){
            int m=0,n=0;
            while(m<dict[i].size()&&n<dict[i+1].size()&&dict[i][m]==dict[i+1][n]){
                m++;n++;
            }
            if(m<dict[i].size()&&n<dict[i+1].size()){
                adj[(int)(dict[i][m])-97].push_back((int)(dict[i+1][n])-97);
            }
        }
        stack<int>track;
        vector<int>vis(k,-1);
        for(int i=0;i<k;i++){
            if(vis[i]==-1){
                vis[i]=1;
                dfs(track,vis,adj,i);
            }
        }
        string res="";
        while(!track.empty()){
            res=res+(char)('a'+track.top());
            track.pop();
        }
        return res;
        // code here
    }
};

