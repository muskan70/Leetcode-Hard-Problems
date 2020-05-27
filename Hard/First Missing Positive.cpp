//First Missing Positive : https://leetcode.com/problems/first-missing-positive/
//Method 1:using set
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                s.insert(nums[i]);
        }
        int ans=1;
        while(s.find(ans)!=s.end())
            ans++;
        return ans;
    }
};

//method 2: index mapping
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++){
           while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
               swap(nums[i],nums[nums[i]-1]);
       } 
       for(int i=0;i<n;i++){
           if(nums[i]!=i+1)
               return i+1;
       } 
       return n+1; 
    }
};