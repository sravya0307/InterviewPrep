/*
1) Graph Coloring
2) Bfs
3) A Bipartite graph is something which can be divided into 2 sets, such that all the edges can be formed by selecting a vertex from each of the sets
4) To acheive this, color the graph using 2 different colors for the vertices on an edge
5) While performing bfs color each level with a different color from the previous level
6) Finally check if any two vertices on an edge have same color

T(C)- O(MXN)
S(C)- O(MXN) - Queue, grid, Color map
*/


class Solution {
public:
    void bfs(vector<vector<int>>& graph,unordered_map<int,int>&color,int m){
        queue<int>q;
        q.push(m);
        int c=1;
        color[m]=c;
        while(!q.empty()){
            q.push(-1);
            (c==1)?c=2:c=1;
            while(q.front()!=-1){
                int t=q.front();
                for(int i=0;i<graph[t].size();i++){
                    if(color.find(graph[t][i])==color.end()){
                        color[graph[t][i]]=c;
                        q.push(graph[t][i]);
                    }
                }
                q.pop();
            }
            q.pop();
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,int>color;
        for(int i=0;i<graph.size();i++){
                if(color.find(i)==color.end()){
                    bfs(graph,color,i);
                }
        }
         for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                if(color[i]==color[graph[i][j]])
                return false;
            }
         }
         return true;
    }
};
