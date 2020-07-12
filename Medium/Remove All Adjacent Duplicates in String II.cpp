//Remove All Adjacent Duplicates in String II : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
//Method1: using extra space - stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() and st.top().first==s[i]){
                st.top().second++;
                if(st.top().second==k)
                    st.pop();
            }
            else
                st.push({s[i],1});
        }
        string ans="";
        while(!st.empty()){
            while(st.top().second){
                ans=st.top().first+ans;
                st.top().second--;
            }
            st.pop();
        }
        return ans;
    }
};

//Method2 : using count array
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> count(s.size());
        for(int i=0;i<s.size();i++){
            if(i==0||s[i]!=s[i-1])
                count[i]=1;
            else{
                count[i]=1+count[i-1];
                if(count[i]==k){
                    s.erase(i-k+1,k);
                    i=i-k;
                }
            }
        }
        return s;
    }
};
