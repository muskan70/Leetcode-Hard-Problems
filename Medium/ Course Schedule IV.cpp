// Course Schedule IV : https://leetcode.com/problems/course-schedule-iv/
class Solution {
public:
     bool check(int src,int cur,int tar,vector<bool> &vis,vector<vector<int>> &a){
        vis[cur]=true;
        if(src!=cur)
            a[src][cur]=1;
        if(cur==tar || a[cur][tar])
            return true;
         
        for(int i=0;i<a[cur].size();i++){
            if(a[cur][i] and !vis[i]){
                a[src][i]=1;
                if(i==tar)
                    return true;
                else if(check(src,i,tar,vis,a))
                    return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> a(n,vector<int>(n,0));
        for(int i=0;i<pre.size();i++)
            a[pre[i][0]][pre[i][1]]=1;
        
        vector<bool> ans;
        for(int i=0;i<q.size();i++){
            vector<bool> vis(n,false);
            ans.push_back(check(q[i][0],q[i][0],q[i][1],vis,a));   
        }
        return ans;
    }
};