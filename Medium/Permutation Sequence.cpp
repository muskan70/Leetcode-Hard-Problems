//Permutation Sequence : https://leetcode.com/problems/permutation-sequence/
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[n+1];
        vector<char> v;
        
        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=fact[i-1]*i;
            v.push_back(char(48+i));
        }
        
        string res="";
        while(n>0){
            int t=(k-1)/fact[n-1];
            res+=v[t];
            v.erase(v.begin()+t);
            k=k-t*fact[n-1];
            n--;
        }
        
        return res;
    }
};