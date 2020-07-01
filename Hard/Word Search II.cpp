//Word Search II : https://leetcode.com/problems/word-search-ii/
class Trie{
    public:
        Trie* children[26];
        string word;
    
        Trie(){
            for(int i=0;i<26;i++)
                children[i]=NULL;
            word="";
        }
    
        ~Trie(){
            for(int i=0;i<26;i++){
                if(children[i])
                    delete children[i];
            }
        }
    
        void insertWord(string s){
            Trie* cur=this;
            for(char c:s){
                if(!cur->children[c-'a'])
                    cur->children[c-'a']=new Trie();
                cur=cur->children[c-'a'];
            }
            cur->word=s;
        }
    };
class Solution {
    void dfs(int i,int j,vector<vector<char>>& board,unordered_set<string> &result,Trie *trie){
        char c=board[i][j];
        if(c=='*') return;
        board[i][j]='*';
        Trie *cur=trie->children[c-'a'];
        
        if(cur){
            if(cur->word!="") result.insert(cur->word);
            if(i>0) dfs(i-1,j,board,result,cur);
            if(j>0) dfs(i,j-1,board,result,cur);
            if(i<board.size()-1) dfs(i+1,j,board,result,cur);
            if(j<board[0].size()-1) dfs(i,j+1,board,result,cur);
        }
        board[i][j]=c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size()==0 || board.size()==0)
            return {};
        Trie trie;
        for(string s:words)
            trie.insertWord(s);
        
        unordered_set<string> result;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i,j,board,result,&trie);
            }
        }
        vector<string> ans(result.begin(),result.end());
        return ans;
    }
};
