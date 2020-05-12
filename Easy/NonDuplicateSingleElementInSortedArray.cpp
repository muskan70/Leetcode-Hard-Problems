//O(log(n)) Approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(l==r)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[r]!=nums[r-1])
            return nums[r];
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])
               return nums[mid];
            else if((mid%2==0 and nums[mid]==nums[mid+1])||(mid%2==1 and nums[mid]==nums[mid-1]))
               l=mid+1;
            else
               r=mid-1;
        }
        return -1;
    }
};

//O(n) Approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans=ans^nums[i];
        return ans;
    }
};

//O(log(n)) simple neat code using XOR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]==nums[mid^1])
                l=mid+1;
            else
                r=mid;    
        }
        return nums[l];
    }
};