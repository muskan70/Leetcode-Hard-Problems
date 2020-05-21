//Check if There is a Valid Path in a Grid : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
class Solution {
public:
    typedef struct cell{
        int hor[2]={-1,-1};
        int ver[2]={-1,-1};
    } cell;
    bool reach=false;
    void dfs(vector<vector<cell>> &pos,vector<vector<bool>> &vis,int i,int j,int m,int n){
        vis[i][j]=true;
        if(i==m-1 and j==n-1){
            reach=true;
            return ;
        }
        if(pos[i][j].hor[0]==1 and j-1>=0 and !vis[i][j-1] and pos[i][j-1].hor[1]==1)
            dfs(pos,vis,i,j-1,m,n);
        if(pos[i][j].hor[1]==1 and j+1<n and !vis[i][j+1] and pos[i][j+1].hor[0]==1)
            dfs(pos,vis,i,j+1,m,n);
        if(pos[i][j].ver[0]==1 and i-1>=0 and !vis[i-1][j] and pos[i-1][j].ver[1]==1)
            dfs(pos,vis,i-1,j,m,n);
        if(pos[i][j].ver[1]==1 and i+1<m and !vis[i+1][j] and pos[i+1][j].ver[0]==1)
            dfs(pos,vis,i+1,j,m,n);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<cell>> pos(m,vector<cell>(n));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    pos[i][j].hor[0]=1;
                    pos[i][j].hor[1]=1;         
                }
                else if(grid[i][j]==2){
                    pos[i][j].ver[0]=1;
                    pos[i][j].ver[1]=1;         
                }
                else if(grid[i][j]==3){
                    pos[i][j].hor[0]=1;
                    pos[i][j].ver[1]=1;         
                }
                else if(grid[i][j]==4){
                    pos[i][j].hor[1]=1;
                    pos[i][j].ver[1]=1;         
                }
                else if(grid[i][j]==5){
                    pos[i][j].hor[0]=1;
                    pos[i][j].ver[0]=1;         
                }
                else if(grid[i][j]==6){
                    pos[i][j].hor[1]=1;
                    pos[i][j].ver[0]=1;         
                }
            }
        }
        dfs(pos,vis,0,0,m,n);
        return reach;
    }
};