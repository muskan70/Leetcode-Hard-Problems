//Max Dot Product of Two Subsequences : https://leetcode.com/problems/max-dot-product-of-two-subsequences/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
            dp[i][0]=INT_MIN;
        for(int i=1;i<=n2;i++)
            dp[0][i]=INT_MIN;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=nums1[i-1]*nums2[j-1];
                if(dp[i-1][j-1]!=INT_MIN)
                    dp[i][j]=max(dp[i][j],max(dp[i-1][j-1],dp[i][j]+dp[i-1][j-1]));
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n1][n2];
    }
};