struct TreeNode* searchBST(struct TreeNode* root, int val) {
        struct TreeNode* temp = root ;
        while(root != NULL ){
            if(root->val == val ){
                return root ;
            }
            else if(root->val > val ){
                root= root->left;
            }
            else{
                root = root->right ;

            }

        }
        return NULL ;
}