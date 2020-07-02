//Subarray Sums Divisible by K : https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int,int> mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            int x=(sum%K+K)%K;
            if(mp.count(x))
                ans+=mp[x];
            mp[x]++;
        }
        return ans;
    }
};
