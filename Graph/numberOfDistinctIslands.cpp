/*
1) Identify distinct connected components, for the connected components using bfs, 
2) after identifying them, for the distinct ones, giving the same index for the ones in the same connected component
3) Using an unordered_map to store the i,j values of same connected components
4) Now while traversing, removing the min of x and min of y from each x and y of a component
5) using a set to identify distinct ones
T(C)= O(MXN)
S(C)= O(MXN)
*/

class Solution {
  public:
    void bfs(int k,int l,vector<vector<int>>&grid,int c){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({k,l});
        while(!q.empty()){
            q.push({-1,-1});
            while(q.front().first!=-1){
                int i=q.front().first,j=q.front().second;
                if(i>0&&grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j]=c;
                }
                if(j>0&&grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1]=c;
                }
                if(i<m-1&&grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j]=c;
                }
                if(j<n-1&&grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1]=c;
                }
                q.pop();
            }
            q.pop();
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size(),c=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    c++;
                    bfs(i,j,grid,c);
                }
            }
        }
        
        unordered_map<int,vector<pair<int,int>>>u;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    u[grid[i][j]].push_back({i,j});
                }
            }
        }
        set<vector<pair<int,int>>>s;
        for(auto it=u.begin();it!=u.end();it++){
                int x=INT_MAX,y=INT_MAX;
            for(int j=0;j<it->second.size();j++){
                x=min(x,it->second[j].first);
                y=min(y,it->second[j].second);
            }
            for(int j=0;j<it->second.size();j++){
                it->second[j].first-=x;
                it->second[j].second-=y;
            }
            s.insert(it->second);
        }
        return s.size();
        
        // code here
    }
};
