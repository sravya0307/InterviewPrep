/*
1) This Approach is different from the one in the cycle in Undirected Graph, since, here there can be a case, where, the neighbour of current node can be present in the
visited array but can be in the different direction, and not form cycle.
2) So, in this approach it's important to track the path traversed until now, and check if the neighbour being visited is in the path traversed or is just visited.
3) If it is in the path, then there is a cycle, to track this, along with the traditional DFS, we take an extra pathvis array to track the path being traversed.

T(C)- O(V+E)
S(C)- O(NXN)- adjlist, prerequisites, stack space, vis, pathvis
*/


class Solution {
public:
    bool dfs(int n,vector<vector<int>>&adjlist,vector<int>&vis,vector<int>&pathvis,int curr){
        bool a=true;
        for(int i=0;i<adjlist[curr].size();i++){
            if(vis[adjlist[curr][i]]==-1){
                vis[adjlist[curr][i]]=1;
                pathvis[adjlist[curr][i]]=1;
                a=(a&&dfs(n,adjlist,vis,pathvis,adjlist[curr][i]));
                pathvis[adjlist[curr][i]]=-1;
            }
            else if(pathvis[adjlist[curr][i]]==1){
               return false;
            }
        }
        return a;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjlist(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(numCourses,-1);
        vector<int>pathvis(numCourses,-1);
        bool res=true;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==-1){
                vis[i]=1;
                pathvis[i]=1;
            res=(res&&dfs(numCourses,adjlist,vis,pathvis,i));
            pathvis[i]=-1;
            }
        }
        return res;
    }
};
