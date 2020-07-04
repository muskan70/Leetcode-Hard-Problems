//Prison Cells After N Days : https://leetcode.com/problems/prison-cells-after-n-days/
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> ans(8,0);
        vector<vector<int>> seen;
        while(N--){
            for(int i=1;i<7;i++)
                ans[i]=cells[i-1]==cells[i+1];
            if(seen.size() and seen.front()==ans) return seen[N%seen.size()]; 
            seen.push_back(ans);
            cells=ans;
        }
        return cells;
    }
};
