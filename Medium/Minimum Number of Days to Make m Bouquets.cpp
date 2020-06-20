//Minimum Number of Days to Make m Bouquets : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        if(a.size()<m*k)
            return -1;
        int maxday=INT_MIN;
        int minday=INT_MAX;
        
        for(auto i:a){
            maxday=max(i,maxday);
            minday=min(i,minday);
        }
        while(minday<maxday){
            int mid=(minday+maxday)/2;
            int ans=check(a,mid,k);
            if(ans<m)
                minday=mid+1;
            else
                maxday=mid;
        }
        return minday; 
    }
    int check(vector<int>& a,int mid,int k){
        int ans=0,col=0;
        for(auto i:a){
            if(i<=mid)
                col++;
            else
                col=0;
            if(col==k){
                ans++;
                col=0;
            }
        }
        return ans;
    }
};