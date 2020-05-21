//Form Largest Integer With Digits That Add up to Target : https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target+1,-1);
        vector<int> dig(target+1,-1);
        dp[0]=0;
        for(int i=1;i<=target;i++){
            for(int d=9;d>=1;d--){
                if(i>=cost[d-1] and dp[i-cost[d-1]]!=-1){
                    if(1+dp[i-cost[d-1]]>dp[i]){
                        dp[i]=1+dp[i-cost[d-1]];
                        dig[i]=d;
                    }
                }
            }
        }
        if(dp[target]==-1)
            return "0";
        string ans="";
        while(target){
            ans+=char(dig[target]+'0');
            target-=cost[dig[target]-1];
        }
        return ans;
    }
};