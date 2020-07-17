//Recover a Tree From Preorder Traversal : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        unordered_map<int,TreeNode*> level;
        int c=0;
        TreeNode* root;
        for(int i=0;i<S.size();){
            if(S[i]=='-'){
                i++;
                c++;
            }
            else{
                string n="";
                while(i<S.size() and S[i]>='0' and S[i]<='9'){
                    n+=S[i];
                    i++;
                }
                level[c]=new TreeNode(stoi(n));
                if(c>0){
                    TreeNode* parent=level[c-1];
                    if(parent->left==NULL)
                        parent->left=level[c];
                    else if(!parent->right)
                        parent->right=level[c];
                }
                else
                    root=level[c];
                c=0;
            }
        }
        return root;
    }
};
