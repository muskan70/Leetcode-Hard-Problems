//Insufficient Nodes in Root to Leaf Paths : https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
class Solution {
public:
    TreeNode* check(TreeNode* root, int limit,int sum) {
        if(root==NULL)
            return NULL;
        if(root->left==NULL and root->right==NULL){
            if(sum+root->val>=limit)
                return root;
            else
                return NULL;
        }
        root->left=check(root->left,limit,sum+root->val);
        root->right=check(root->right,limit,sum+root->val);
        if(!root->left and !root->right)
            return NULL;
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return check(root,limit,0);
    }
};