//Maximum Score After Splitting a String : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
class Solution {
public:
    int maxScore(string s) {
        int ans=0,n=s.size(),o=0,z=0;
    
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                o++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='0')
                z++;
            else
                o--;
            ans=max(ans,o+z);
        }  
        return ans;
    }
};