//Constrained Subsequence Sum : https://leetcode.com/problems/constrained-subsequence-sum/
//Method1 : Dp - O(nk)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int maxsum[nums.size()];
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxsum[i]=nums[i];
            for(int j=i-1;j>=0 and i-j<=k;j--){
                maxsum[i]=max(maxsum[i],nums[i]+maxsum[j]);
            }
            //cout<<maxsum[i]<<" ";
            ans=max(ans,maxsum[i]);
        }
        return ans;
    }
};

//Method2 : deque - O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            nums[i]+=q.size()?q.front():0;
            ans=max(ans,nums[i]);
            while(q.size() and nums[i]>q.back())
                q.pop_back();
            if(nums[i]>0)
                q.push_back(nums[i]);
            if(i>=k and nums[i-k]==q.front())
                q.pop_front();
        }
        return ans;
    }
};