/*Given a matrix with X's and O's, change the surrounded regions of O's to X's, a surrounded region of O's is entirely surrounded by X's

Approach: Check for the non-surrounded regions using bfs traversal, starting from the Os present in the border, the rest of the Os belong to surrounded regions

Time Complexity: O(M*N)
Space Complexity: O(M*N)
*/


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
            {q.push({i,0});
            vis[i][0]=1;}
            if(board[i][n-1]=='O'){
                vis[i][n-1]=1;
            q.push({i,n-1});}
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O'){
                vis[0][i]=1;
            q.push({0,i});}
            if(board[m-1][i]=='O'){
                vis[m-1][i]=1;
            q.push({m-1,i});}
        }
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            if(i>0&&board[i-1][j]=='O'&&vis[i-1][j]==-1){
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(j>0&&board[i][j-1]=='O'&&vis[i][j-1]==-1){
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
            if(i+1<m&&board[i+1][j]=='O'&&vis[i+1][j]==-1){
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(j+1<n&&board[i][j+1]=='O'&&vis[i][j+1]==-1){
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
            q.pop();
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&vis[i][j]==-1)
                board[i][j]='X';
            }
        }
    }
};
