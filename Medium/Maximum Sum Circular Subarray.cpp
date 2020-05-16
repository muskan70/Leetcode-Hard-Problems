//Maximum Sum Circular Subarray : https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size(); 
        
        int maxx=INT_MIN,minn=INT_MAX,ts=0,s1=0,s2=0;
        for(int i=0;i<n;i++){
            ts+=A[i];
            s1+=A[i];
            s2+=A[i];
            maxx=max(maxx,s1);
            minn=min(minn,s2);
            if(s1<0) s1=0;
            if(s2>0) s2=0;
        }
        if(ts==minn)
            return maxx;
        return max(maxx,ts-minn);
    }
};

//Method2:
class Solution {
    public:
        int solve(vector<int> &v){
            int csum = v[0];
            int ans= v[0];
            for(int i=1;i<v.size();i++){
                csum = max(csum+v[i],v[i]);
                ans=max(ans,csum);
            }
            return ans;
        }
        int maxSubarraySumCircular(vector<int>& A) {
            int a1 = solve(A);
            //  cout<<a1;
            int sum = 0;
            int cnt = 0;
            for(int i=0;i<A.size();i++){
                sum+=A[i];
                if(A[i]<0)cnt++;
                A[i]=(-1)*A[i];
            }
            if(cnt==A.size()) return a1;
            int a2 = solve(A);
            return max(a1,a2+sum);
        }
};