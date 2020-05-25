//Word Break : https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> counts(s.size()+1, 0);
       counts[0] = 1;
       
       for (size_t i = 0; i < s.size(); ++i)  {
           if (counts[i] == 0)
               continue;
           for (size_t j = 0; j < wordDict.size(); ++j) {
               if (s.substr(i, wordDict[j].size()) == wordDict[j]) {
                   counts[i+wordDict[j].size()] = 1;
               }
           }
       }
       
       return counts.back() == 1;
    }
};