//Largest Divisible Subset : https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)
            return vector<int>();
        sort(nums.begin(),nums.end());
        int dp[nums.size()];
        memset(dp,1,sizeof(dp));
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0)
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int maxindex=0;
        for(int i=1;i<nums.size();i++)
            maxindex=dp[i]>dp[maxindex]?i:maxindex;
        vector<int> ans;
        ans.push_back(nums[maxindex]);
        for(int i=maxindex-1;i>=0;i--){
            if(nums[maxindex]%nums[i]==0 and dp[i]==dp[maxindex]-1){
                ans.push_back(nums[i]);
                maxindex=i;
            }
        }
        return ans;
    }
};