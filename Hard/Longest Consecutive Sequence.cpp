//Longest Consecutive Sequence : https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto it:nums)
            mp.insert(it);
            
        int ans=0;    
        for(auto it:mp){
            if(mp.find(it-1)==mp.end()){
                int streak=1;
                int num=it;
                while(mp.find(num+1)!=mp.end()){
                    num++;
                    streak++;
                }
                ans=max(ans,streak);
            }
        }
        return ans;
    }
};