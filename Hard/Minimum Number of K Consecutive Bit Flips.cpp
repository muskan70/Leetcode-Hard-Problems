//Minimum Number of K Consecutive Bit Flips : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
class Solution {
public:
    int minKBitFlips(vector<int>& A, int k) {
        int ans=0,flipped=0;
        deque<int> q;
        for(int i=0;i<A.size();i++){
            if(i>=k)
                flipped^=q.front();
            if(A[i]==flipped){
                if(i+k>A.size())
                    return -1;
                flipped^=1;
                q.push_back(1);
                ans++;
            }
            else
                q.push_back(0);
            if(i>=k)
                q.pop_front();
        }
        return ans;
    }
};