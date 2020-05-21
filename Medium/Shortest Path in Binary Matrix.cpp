//Shortest Path in Binary Matrix : https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        if(grid[0][0]||grid[n-1][n-1])
            return -1;
        if(n==1)
            return 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,1}});
        vis[0][0]=true;
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            pair<int,pair<int,int>> cur=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int x=cur.first+dx[i];
                int y=cur.second.first+dy[i];
                int z=cur.second.second+1;
                if(x==n-1 and y==n-1)
                    return z;
                if(x>=0 and y>=0 and x<n and y<n and !vis[x][y]){
                    vis[x][y]=true;
                    if(!grid[x][y])
                        q.push({x,{y,z}});
                }
            }
        }
        return -1;
    }
};