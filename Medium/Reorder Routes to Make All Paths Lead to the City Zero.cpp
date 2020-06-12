//Reorder Routes to Make All Paths Lead to the City Zero : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
class Solution {
public:
    int dfs(int src,vector<bool> &vis,vector<vector<int>> &a){
        vis[src]=true;
        int ans=0;
        for(auto i:a[src]){
            if(!vis[abs(i)])
                ans+=dfs(abs(i),vis,a)+(i>0);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<int>> a(n);
        for(int i=0;i<c.size();i++){
            a[c[i][0]].push_back(c[i][1]);
            a[c[i][1]].push_back(-c[i][0]);
        }
        vector<bool> vis(n,false);
        return dfs(0,vis,a);
    }
};