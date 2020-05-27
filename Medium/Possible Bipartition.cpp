//Possible Bipartition : https://leetcode.com/problems/possible-bipartition/
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> a[N+1];
        for(int i=0;i<dislikes.size();i++){
            a[dislikes[i][0]].push_back(dislikes[i][1]);
            a[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        int color[N+1];
        memset(color,-1,sizeof(color));
        for(int i=1;i<=N;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int cur=q.front();
                    q.pop();
                    for(auto it:a[cur]){
                        if(color[it]==-1){
                            color[it]=1-color[cur];
                            q.push(it);
                        }
                        else if(color[it]==color[cur])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
