/*
1) Topological sort is the ordering of vertices such that if there is an edge between u and v, u appears before v
2) It is done on Directed Acyclic graphs, if undirected, we cannot decide which to come first u or v for a single edge, if cyclic, there is no proper ordering.
3) By using the traditional DFS along with a stack that stores elements while backtracking, because the ones reached last should appear last, so stack while backtracking(FILO).

T(C)- O(V+E) -dfs
S(C)- O(V+E) -adjlist, n-stack,res
*/

class Solution
{
	public:
	void dfs(vector<int>adj[],vector<int>&vis,stack<int>&track,int cur){

	    for(int i=0;i<adj[cur].size();i++){
	        if(vis[adj[cur][i]]==-1){
	            vis[adj[cur][i]]=1;
	            dfs(adj,vis,track,adj[cur][i]);
	        }
	    }
	    track.push(cur);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>track;
	    vector<int>vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1)
	        {
	            vis[i]=1;
	            dfs(adj,vis,track,i);
	        }
	    }
	    vector<int>res;
	    while(!track.empty()){
	        res.push_back(track.top());
	        track.pop();
	    }
	    return res;
	}
};
