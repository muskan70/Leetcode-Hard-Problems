//Maximum Points You Can Obtain from Cards : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int dp1[k+1],dp2[k+1];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        
        for(int i=0;i<k;i++)
            dp1[i+1]=a[i]+dp1[i];
        for(int i=n-1;i>=n-k;i--)
            dp2[n-i]=dp2[n-i-1]+a[i];
        
        int ans=0;
        for(int i=0,j=k;i<=k;i++,j--)
            ans=max(ans,dp1[i]+dp2[j]);
        return ans;
    }
};