//Count Square Submatrices with All Ones
/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1]){
                    prefix[i][j]=matrix[i-1][j-1] + min(prefix[i-1][j-1],min(prefix[i-1][j],prefix[i][j-1]));
                }
                ans+=prefix[i][j];
            }
        }
        return ans; 
    }
};