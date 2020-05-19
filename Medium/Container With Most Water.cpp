//Container With Most Water: https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    int maxArea(vector<int>& height) {
        int ans=0,left=0,right=height.size()-1;
        while(left<right){
            ans=max(ans,min(height[left],height[right])*(right-left));
            if(height[left]<height[right])
                left++;
            else if(height[left]>height[right])
                right--;
            else{
                left++;
                right--;
            }
        }
        return ans;
    }
};