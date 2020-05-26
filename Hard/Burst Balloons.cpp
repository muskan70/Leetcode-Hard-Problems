//Burst Balloons : https://leetcode.com/problems/burst-balloons/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        

        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int len=1;len<=n;len++){
            for(int left=1;left<=n-len+1;left++){
                int right=left+len-1;
                int ans=0;
                for(int i=left;i<=right;i++){
                    int res=dp[left][i-1]+dp[i+1][right];
                    res+=nums[left-1]*nums[i]*nums[right+1];
                    ans=max(res,ans);
                }
                dp[left][right]=ans;
            }
        }
        return dp[1][n];
    }
};