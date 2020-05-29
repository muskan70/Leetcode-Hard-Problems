//Course Schedule : https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool dfs(int src,bool vis[],vector<vector<int>> &a,bool rec[]){
        vis[src]=true;
        rec[src]=true;
        for(auto it:a[src]){
            if(!vis[it] and !dfs(it,vis,a,rec))
                return false;
            if(rec[it])
                return false;  
        }
        rec[src]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>> a(numCourses,vector<int>());
        for(int i=0;i<edges.size();i++)
            a[edges[i][1]].push_back(edges[i][0]);
        bool vis[numCourses];
        bool rec[numCourses];
        memset(vis,false,sizeof(vis));
        memset(rec,false,sizeof(rec));
        for(int i=0;i<numCourses;i++)
            if(!vis[i] and !dfs(i,vis,a,rec))
                return false;
        return true;
    }
};