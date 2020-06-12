//Target Sum : https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum<S || ((S+sum)&1))
            return 0;
        int k=(S+sum)>>1;
        int dp[k+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(auto n:nums){
            for(int i=k;i>=n;i--)
                dp[i]+=dp[i-n];
        }
        return dp[k];
    }
};