//Find Two Non-overlapping Sub-arrays Each With Target Sum : https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int best[arr.size()];
        memset(best,INT_MAX,sizeof(best));
        int start=0,sum=0,ans=INT_MAX,temp=INT_MAX;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[start++];
            }
            if(sum==target){
                if(start>0 and best[start-1]!=INT_MAX)
                    ans=min(ans,best[start-1]+i-start+1);
                temp=min(temp,i-start+1);   
            }
            best[i]=temp;
        }
        return ans==INT_MAX?-1:ans;
            
    }
};