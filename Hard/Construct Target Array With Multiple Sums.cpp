//Construct Target Array With Multiple Sums: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long s=0;
        for(auto it:target){
            s+=it;
            pq.push(it);
        }
        while(s>1 and pq.top()>s/2){
            int cur=pq.top();
            pq.pop();
            s-=cur;
            if(s<=1)
                return s;
            pq.push(cur%s);
            s+=cur%s;
        }
        return s==target.size();
    }
};