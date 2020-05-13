//Minimum Time to Collect All Apples in a Tree : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple, otherwise, it does not have any apple.

 
*/
class graph{
    public:
    int v;
    list<int> *a;
    
    graph(int n){
        v=n;
        a=new list<int>[n];
    }
    void addedge(int u,int v){
        a[u].push_back(v);
        a[v].push_back(u);
    }
    pair<bool,int> dfs(int src,bool vis[],vector<bool>& hasApple){
        //cout<<src<<"\n";
        vis[src]=true;
        pair<bool,int> ans;
        for(auto i:a[src]){
            if(!vis[i]){
                auto p=dfs(i,vis,hasApple);
                if(p.first){
                    ans.second+=(p.second+2);
                    ans.first=true;
                }
            }
        }
        if(hasApple[src])
            ans.first=true;
        //cout<<src<<" "<<ans.first<<" "<<ans.second<<"\n";
        return ans;
    }
};

class Solution {
public:
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph g(n);
        for(int i=0;i<edges.size();i++)
            g.addedge(edges[i][0],edges[i][1]);
        bool vis[n];
        memset(vis,false,sizeof(vis));
        return g.dfs(0,vis,hasApple).second;
    }
};

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