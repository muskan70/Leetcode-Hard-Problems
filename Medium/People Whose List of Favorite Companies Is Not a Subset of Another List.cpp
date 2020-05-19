//People Whose List of Favorite Companies Is Not a Subset of Another List : https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
//Method1 : O(n^2 *m) n-list of people with favorite companies , m=size of one person list 
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& a) {
        map<string,vector<int>> mp;
        vector<int> ans;

        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                mp[a[i][j]].push_back(i);
            }
        }
        for(int i=0;i<a.size();i++){
            unordered_map<int,int> k;
            for(auto j:a[i]){
                for(auto x:mp[j])
                    k[x]++;
            }
            bool flag=true;
            for(auto it:k){
                if(it.second==a[i].size() and it.first!=i){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};

//Method 2: (O(n^2))
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& a) {
        map<string,int> mp;
        int id=1;
        vector<int> ans;

        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(!mp.count(a[i][j]))
                    mp[a[i][j]]=id++;
            }
        }
        vector<bitset<50001>> vec;
        for(int i=0;i<a.size();i++){
            bitset<50001> b; 
            for(auto j:a[i])
                b[mp[j]]=1;
            vec.push_back(b);
        }
                
        for(int i=0;i<a.size();i++){
            bool flag=true;
            for(int j=0;j<a.size();j++){
                if(i==j) continue;
                if((vec[i] & vec[j])==vec[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(i);
        }   
        return ans;
    }
};
