//Substring with Concatenation of All Words : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.size()==0||words.size()==0)
            return ans;
        
        unordered_map<string,int> mp;
        int l=0,wl=words[0].size();
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
            l+=words[i].size();
        }
        if(l>s.size())
            return ans;
        
        for(int i=0;i<=s.size()-l;i++){
            unordered_map<string,int> temp(mp);
            int count=words.size(),j=i;
            while(j<i+l){
                string f=s.substr(j,wl);
                if(temp.find(f)==temp.end()||temp[f]==0)
                    break;
                else{
                    temp[f]--;
                    count--;
                }
                j+=wl;
            }
            if(count==0)
                ans.push_back(i);
        }
        return ans;
    }
};