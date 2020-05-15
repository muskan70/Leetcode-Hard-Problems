//Find the Kth Smallest Sum of a Matrix With Sorted Rows : https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        int sum=0;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        map<vector<int>,bool> vis;
        vector<int> temp(n,0);
        vis[temp]=true;
        
        for(int i=0;i<n;i++)
            sum+=mat[i][0];
        
        pq.push(make_pair(sum,temp));
        int x=0;
        vis[temp]=true;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            x++;
            if(x==k)
                return p.first;
            
            for(int i=0;i<n;i++){
                sum=p.first;
                temp=p.second;
                int j=temp[i];
                if(j+1<m){
                    sum-=mat[i][j];
                    sum+=mat[i][j+1];
                    temp[i]=j+1;
                    if(vis.find(temp)==vis.end()){
                        vis[temp]=true;
                        pq.push({sum,temp});
                    }
                }    
            }
        }
        return 0;
    }
};