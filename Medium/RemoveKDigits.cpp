//Remove K Digits

//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

//Method 1: greedy stack ---time:O(n),space:O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        for(int i=0;i<num.size();i++){
            int cur=int(num[i]-48);
            while(!s.empty() and cur<s.top() and k>0){
                s.pop();
                k--;
            }
            s.push(cur);
        }
        while(k and !s.empty()){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans+=char(s.top()+48);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size()>1 and ans[0]=='0')
            ans=ans.substr(1);
        
        if(ans=="")
            return "0";
        return ans;
            
    }
};

//Method 2: greedy ---time:O(n),space:O(1)
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(int i=0;i<num.size();i++){
            while(k and ans.size() and ans.back()>num[i]){
                ans.pop_back();
                k--;
            }
            if(ans.length()||num[i]!='0')
                ans.push_back(num[i]);
        }
        while(k-- and ans.length())
            ans.pop_back();
        
        if(ans=="")
            return "0";
        return ans;
            
    }
};
