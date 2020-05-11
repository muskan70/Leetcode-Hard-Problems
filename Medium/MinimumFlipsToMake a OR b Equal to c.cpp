//1318. Minimum Flips to Make a OR b Equal to c : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(c){
            if(c&1){
                if(a&1 || b&1);
                else
                    ans++;
            }
            else{
                if(a&1)
                    ans++;
                if(b&1)
                    ans++;
            }
            c=c>>1;
            a=a>>1;
            b=b>>1;
        }
        while(a){
            ans++;
            a=a&(a-1);
            }
        while(b){
            ans++;
            b=b&(b-1);
            }    
        return ans;
    }
};
