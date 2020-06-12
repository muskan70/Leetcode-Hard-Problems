//Largest 1-Bordered Square : https://leetcode.com/problems/largest-1-bordered-square/
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ver[n][m],hor[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ver[i][j]=(i==0)?1:1+ver[i-1][j];
                    hor[i][j]=(j==0)?1:1+hor[i][j-1];
                }
                else{
                    ver[i][j]=0;
                    hor[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t=min(ver[i][j],hor[i][j]);
                while(t>ans){
                    if(ver[i][j-t+1]>=t and hor[i-t+1][j]>=t)
                        ans=t;
                    t--;
                }
            }
        }
        return ans*ans;
    }
};