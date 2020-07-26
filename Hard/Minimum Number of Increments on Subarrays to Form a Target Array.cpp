//Minimum Number of Increments on Subarrays to Form a Target Array : https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0,pre=0;
        for(int i=0;i<target.size();i++){
            ans+=max(target[i]-pre,0);
            pre=target[i];
        }
        return ans;
    }
};
