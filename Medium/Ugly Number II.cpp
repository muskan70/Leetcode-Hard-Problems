//Ugly Number II : https://leetcode.com/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        int next_ugly=1;
        int x=0,y=0,z=0;
        ugly[0]=1;
        int next2=2,next3=3,next5=5;
        for(int i=1;i<n;i++){
            next_ugly=min(next2,min(next3,next5));
            ugly[i]=next_ugly;
            if(next_ugly==next2){
                x++;
                next2=ugly[x]*2;
            }
            if(next_ugly==next3){
                y++;
                next3=ugly[y]*3;
            }
            if(next_ugly==next5){
                z++;
                next5=ugly[z]*5;
            }
        }
        return next_ugly;
    }
};
