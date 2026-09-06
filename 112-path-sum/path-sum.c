bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL ){
        return false ;
    }

    targetSum = targetSum - root->val ;
    if(root->left == NULL && root->right == NULL ){
        return targetSum == 0 ;
    }
    
    return hasPathSum(root->left , targetSum) || hasPathSum(root->right , targetSum) ;
}