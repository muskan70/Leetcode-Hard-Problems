//Minimum Swaps to Arrange a Binary Grid : https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)
                    count++;
                else    
                    break;
            }
            v[i]=count;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int k=i;
            int req=n-1-i;
            while(k<n and v[k]<req) k++;
            if(k==n) return -1;
            ans+=k-i;
            while(k>i){
                v[k]=v[k-1];
                k--;
            }
        }
        return ans;
    }
};
