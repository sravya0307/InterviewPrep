//Finding the nearest 0's with the concept of BFS, starting with pushing all the 0's into the queue


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>res(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        int dis=0;
        while(!q.empty()){
            dis++;
            q.push({-1,-1});
            while(q.front().first!=-1){
                int i=q.front().first,j=q.front().second;
                if(i+1<m&&res[i+1][j]==-1){
                    q.push({i+1,j});
                    res[i+1][j]=dis;
                }
                if(j+1<n&&res[i][j+1]==-1){
                    res[i][j+1]=dis;
                    q.push({i,j+1});
                }
                if(i>0&&res[i-1][j]==-1){
                    res[i-1][j]=dis;
                    q.push({i-1,j});
                }
                if(j>0&&res[i][j-1]==-1){
                    res[i][j-1]=dis;
                    q.push({i,j-1});
                }
                q.pop();
            }
            q.pop();
        }
        return res;
    }
};
