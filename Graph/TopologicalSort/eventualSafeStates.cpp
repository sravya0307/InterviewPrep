/*
1) This problem states, to find the nodes from which no single path can lead to a loop or a non-terminal node(terminal is the one with no outgoing edges)
and these nodes are known to be Safe nodes. Return all the safenodes in increasing order.
2) This can be approached with dfs traversal of a node and check whether, this can lead to a cycle, incase it does, backtrack and mark all the traversed nodes as Unsafe.
3) By repeating this process for all the connected components, the ones that are not marked unsafe can be returned.
3) To detect cycle, use pathvis, to track the path traversed until now, maintain an issafe array to mark while backtracking.
4) While backtracking, mark unsafe, when found a cycle or an unsafe node.

T(C)- O(V+E)- dfs
S(C)- O(V+E)- adjlist, vis, pathvis, issafe- n

*/

class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis,vector<bool>&issafe,int cur){
        bool safe=true;
        for(int i=0;i<graph[cur].size();i++){
            if(vis[graph[cur][i]]==-1){
                vis[graph[cur][i]]=1;
                pathvis[graph[cur][i]]=1;
                safe=(dfs(graph,vis,pathvis,issafe,graph[cur][i])&&safe);
                pathvis[graph[cur][i]]=-1;
            }
            else if(pathvis[graph[cur][i]]==1||(!issafe[graph[cur][i]])){
                safe=false;
                break;
            }
        }
        issafe[cur]=safe;
        return safe;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
       vector<int>vis(n,-1);
       vector<int>pathvis(n,-1);
       vector<bool>issafe(n,true);
       vector<int>res;
       for(int i=0;i<graph.size();i++){
        if(vis[i]==-1){
            vis[i]=1;
            pathvis[i]=1;
            dfs(graph,vis,pathvis,issafe,i);
            pathvis[i]=-1;
        }
       }
       for(int i=0;i<n;i++){
        if(issafe[i])
        res.push_back(i);
       }
       return res;
       
    }
};

