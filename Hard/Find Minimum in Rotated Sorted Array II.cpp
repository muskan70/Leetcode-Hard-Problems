//Find Minimum in Rotated Sorted Array II : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int ans=INT_MAX;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r])
                l=mid+1;
            else if(nums[mid]<nums[l]){
                    r=mid;
                    l++;
            }
            else
                r--;
        }
        return nums[l];
    }
};
