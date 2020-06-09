//Last Stone Weight II : https://leetcode.com/problems/last-stone-weight-ii/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0,n=stones.size();
        for(int i=0;i<n;i++)
            sum+=stones[i];
        int w=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                int withoutcur=dp[i-1][j],withcur=0;
                if(j>=stones[i-1])
                    withcur=stones[i-1]+dp[i-1][j-stones[i-1]];
                dp[i][j]=max(withcur,withoutcur);
            }
        }
        int suma=dp[n][w],sumb=sum-suma;
        return sumb-suma;
    }
};