//Numbers With Same Consecutive Differences : https://leetcode.com/problems/numbers-with-same-consecutive-differences/
//Method1: Recursive approach
class Solution {
public:
    vector<int> build(int n,int k,int prev){
        if(n==0)
            return vector<int>();
        if(k==0){
            int num=0;
            while(n--)
                num=num*10+prev;
            return {num};
        }
            
        vector<int> ans;
        if(prev-k>=0){
            vector<int> temp=build(n-1,k,prev-k);
            if(temp.size()==0)
                ans.push_back(prev-k);
            else    
                for(auto x:temp)
                    ans.push_back((prev-k)*pow(10,n-1)+x);
        }
        if(prev+k<=9){
            vector<int> temp=build(n-1,k,prev+k);
            if(temp.size()==0)
                ans.push_back(prev+k);
            else    
                for(auto x:temp)
                    ans.push_back((prev+k)*pow(10,n-1)+x);
        }
        
        return ans;
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if(N==1){
            for(int i=0;i<10;i++)
                ans.push_back(i);
            return ans;
        }
            
        for(int i=1;i<=9;i++){
            vector<int> temp=build(N-1,K,i);
                for(auto x:temp)
                    ans.push_back(i*pow(10,N-1)+x);
        }
        return ans;
    }
};
