//Diagonal Traverse II:https://leetcode.com/problems/diagonal-traverse-ii/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[(i+j)].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<mp.size();i++){
            for(int j=mp[i].size()-1;j>=0;j--){
                ans.push_back(mp[i][j]);
            }
        }
        return ans;    
    }
};