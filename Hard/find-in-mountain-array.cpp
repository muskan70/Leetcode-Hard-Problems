//Find in Mountain Array : https://leetcode.com/problems/find-in-mountain-array/
/*
Intuition
1.Binary find peak in the mountain.
2.Binary find the target in strict increasing array
3.Binary find the target in strict decreasing array
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int k, MountainArray &a) {
        int n=a.length();
        int l=0,r=n-1;
        int peak=-1;
        while(l<r){
            int m=(l+r)/2;
            if(a.get(m)<a.get(m+1))
                l=peak=m+1;
            else
                r=m;
        }
        l=0;r=peak;
        int ans;
        while(l<=r){
            int m=(l+r)/2;
            if(a.get(m)==k)
                return m;
            else if(a.get(m)>k)
                r=m-1;
            else
                l=m+1;
        }
        l=peak;r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(a.get(m)==k)
                return m;
            else if(a.get(m)>k)
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};