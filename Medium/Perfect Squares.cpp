// Perfect Squares : https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int ans=INT_MAX;
            int j=1;
            while(i-j*j>=0){
                ans=min(ans,dp[i-j*j]+1);
                j++;
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};
