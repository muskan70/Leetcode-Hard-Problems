//Corporate Flight Bookings : https://leetcode.com/problems/corporate-flight-bookings/

//Method1: O(n^2)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(int x=0;x<bookings.size();x++){
            for(int i=bookings[x][0];i<=bookings[x][1];i++)
                ans[i-1]+=bookings[x][2];
        }
        return ans;
    }
};

//Method2: O(n)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(int x=0;x<bookings.size();x++){
            ans[bookings[x][0]-1]+=bookings[x][2];
            if(bookings[x][1]<n)
                ans[bookings[x][1]]-=bookings[x][2];
        }
        for(int i=1;i<n;i++)
            ans[i]+=ans[i-1];
        return ans;
    }
};