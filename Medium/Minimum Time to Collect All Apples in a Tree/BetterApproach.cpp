//Minimum Time to Collect All Apples in a Tree : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans=0;
        for(int i=edges.size()-1;i>=0;i--){
            if(hasApple[edges[i][1]]){
                ans++;
                hasApple[edges[i][0]]=true;
            }
        }
        return ans*2;
    }
};
//This approach is only valid if edges are given from root to leaves order.