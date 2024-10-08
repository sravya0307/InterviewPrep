/*
1) Topological sort also known as Kahn's algorithm, can also be used for the cycle detection in directed Graph
2) Topo sort, focuses on the concept of indegree
3) Indegree is the number of edges coming into a node, if the indegree of a node is 0, that means no node is depending on the current node, hence it can safely be removed.
4) If there is a cycle in a directed graph, there comes a case, where every node is dependent on another node, and no node can be found of indegree 0, similar to the deadlock situation.
5) So, the process is to remove the ones with indegree 0, and decrement the indegree of the nodes, which were initially connected to the node with indegree 0.
6) For this process to happen, we can use a queue to store nodes of indegree 0, and decrement the indegrees of nodes connected to them, then push the ones that now has indegree 0.
7) Repeat the process, once no node is of indegree 0 to be found, navigate through indegrees of all the nodes, and if there are nodes yet with positive indegrees, this indicates there is a cycle!
8) This solution also provides for course scheduling.

T(C)- O(V+E)-queue+O(n*n)-prerequisites
S(C)- O(n*n)- adjlist, n-Queue, n-vector-indegree
*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indeg(numCourses,0);
        vector<int>res;
        vector<vector<int>>adjlist(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int k=q.front();
            for(int i=0;i<adjlist[k].size();i++){
                indeg[adjlist[k][i]]--;
                if(indeg[adjlist[k][i]]==0)
                q.push(adjlist[k][i]);
            }
            res.push_back(q.front());
            q.pop();
        }
        for(auto i:indeg){
            if(i!=0)
            return {};
        }
        return res;
    }
};
