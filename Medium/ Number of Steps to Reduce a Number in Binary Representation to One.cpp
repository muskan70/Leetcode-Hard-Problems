// Number of Steps to Reduce a Number in Binary Representation to One : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
class Solution {
public:
    int numSteps(string s) {
        int i=s.size()-1;
        int ans=0;
        while(i>0){
            //cout<<i<<"\n";
            if(s[i]=='0'){
                ans++;
                i--;
            }
            else{
                ans++;
                while(i>=0 and s[i]=='1'){
                    //cout<<i<<" "<<ans<<"\n";
                    ans++;
                    i--;
                }
                //cout<<i<<"\n";
                if(i>=0)
                    s[i]='1';
                
            }
        }
        return ans;
    }
};