//Task Scheduler: https://leetcode.com/problems/task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int count=0,ans=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            count=max(count,mp[tasks[i]]);
        }
        ans=(count-1)*(n+1);
        for(auto it:mp)
            if(it.second==count)
                ans++;
        return max(ans,int(tasks.size()));
    }
};
