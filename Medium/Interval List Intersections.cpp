//Interval List Intersections : https://leetcode.com/problems/interval-list-intersections/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i=0,j=0,n=A.size(),m=B.size();
        while(i<n and j<m){
            //cout<<i<<" "<<j<<"\n";
            int start=max(A[i][0],B[j][0]);
            int end=min(A[i][1],B[j][1]);
            //cout<<start<<" "<<end<<"\n";
            if(start<=end) ans.push_back(vector<int>{start,end});
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};