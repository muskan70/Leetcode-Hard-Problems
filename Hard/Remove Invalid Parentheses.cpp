//Remove Invalid Parentheses : https://leetcode.com/problems/remove-invalid-parentheses/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        queue<string> q;
        q.push(s);
        vector<string> ans;
        
        while(!q.empty()){
            string cur=q.front();
            q.pop();
            if(valid(cur)) ans.push_back(cur);
            
            else if(ans.empty()){
                for(int i=0;i<cur.size();i++){
                    if(cur[i]=='('||cur[i]==')'){
                        string temp=cur.substr(0,i)+cur.substr(i+1);
                        if(!st.count(temp)){
                            st.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            
        }
        return ans;
    }
    bool valid(string s){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                c++;
            else if(s[i]==')'){
                if(c==0) return false;
                c--;
            }
        }
        return !c;
    }
};
