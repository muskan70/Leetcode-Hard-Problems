//Kth Smallest Element in a BST : 
int check(TreeNode* root, int &k) {
        if(root==NULL)
            return INT_MIN;
        //cout<<root->val<<" ";
        int ans=check(root->left,k);
        if(ans!=INT_MIN)
            return ans;
        k--;
        if(k==0)
            return root->val;
        return check(root->right,k);
            
    
    }
    int kthSmallest(TreeNode* root, int k) {
        return check(root,k);
    }
