//Cheapest Flights Within K Stops : https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int K) {
        vector<pair<int,int>> v[n];
        for(int i=0;i<arr.size();i++)
            v[arr[i][0]].push_back({arr[i][1],arr[i][2]});
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{src,K+1}});
        while(!pq.empty()){
            pair<int,pair<int,int>> x=pq.top();
            pq.pop();
            if(x.second.first==dst)
                return x.first;
            if(x.second.second==0)
                continue;
            for(auto it:v[x.second.first]){
                pq.push({x.first+it.second,{it.first,x.second.second-1}});
            }
        }
        return -1;
    }
};