//Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxq,minq;
        int i=0,j;
        for(j=0;j<nums.size();j++){
            while(maxq.size() and nums[j]>maxq.back()) maxq.pop_back();
            while(minq.size() and nums[j]<minq.back()) minq.pop_back();
            maxq.push_back(nums[j]);
            minq.push_back(nums[j]);
            if(maxq.front()-minq.front()>limit){
                if(nums[i]==maxq.front()) maxq.pop_front();
                if(nums[i]==minq.front()) minq.pop_front();
                i++;
            }
        }
        return j-i;
    }
};