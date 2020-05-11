//Number of Ways of Cutting a Pizza : https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
class Solution {
public:
    int dfs(vector<vector<vector<int>>> &dp,vector<vector<int>> &prefix,int k,int i,int j,int n,int m){
        if(prefix[i][j]==0)
            return 0;
        if(k==0)
            return 1;
        if(dp[k][i][j]!=-1)
            return dp[k][i][j];
        int ans=0;
        //cut horizontally
        for(int r=i+1;r<n;r++){
            if(prefix[i][j]-prefix[r][j]>0)
                ans=(ans+dfs(dp,prefix,k-1,r,j,n,m))%1000000007;
        }
        //cut vertically
        for(int c=j+1;c<m;c++){
            if(prefix[i][j]-prefix[i][c]>0)
                ans=(ans+dfs(dp,prefix,k-1,i,c,n,m))%1000000007;
        }
        dp[k][i][j]=ans;
        return ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        int n=pizza.size(),m=pizza[0].size();
        vector<vector<vector<int>>> dp=vector(k,vector(n,vector(m,-1)));
        vector<vector<int>> prefix=vector(n+1,vector(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                prefix[i][j]=prefix[i+1][j]+prefix[i][j+1]-prefix[i+1][j+1]+(pizza[i][j]=='A');
            }
        }
        return dfs(dp,prefix,k-1,0,0,n,m);
    }
};