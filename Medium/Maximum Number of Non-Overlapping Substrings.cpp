//Maximum Number of Non-Overlapping Substrings : https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        
        //min and max position of each letter
        vector<int> left(26,n+1),right(26,-1);
        for(int i=0;i<n;i++){
            left[s[i]-'a']=min(left[s[i]-'a'],i);
            right[s[i]-'a']=max(right[s[i]-'a'],i);
        }
        
        //merge intervals
        vector<pair<int,int>> v;
        for(int i=0;i<26;i++){
            int start=left[i];
            int end=right[i];
            for(int j=start+1;j<end;j++){
                start=min(start,left[s[j]-'a']);
                end=max(end,right[s[j]-'a']);
            }
            if(start<n and start==left[i])
                v.push_back({end,start});
        }
        
        //find maximum substrings
        sort(v.begin(),v.end());
        vector<string> ans;
        int prev=-1;
        for(auto &[end,start]:v){
            if(start>prev){
                ans.push_back(s.substr(start,end-start+1));
                prev=end;
            }
        }
        return ans;
    }
};
