class Solution {
public:
    int max(int a , int b){
        return (a>b) ? a : b ;
    }
    int dfs(struct TreeNode* node , int* max_sum){
        if(node == NULL ){
            return 0;
        }
        int left = max(0,dfs(node->left , max_sum));
        int right = max(0,dfs(node->right , max_sum));

        int current_split = node->val + left + right ;
        if(current_split > *max_sum){
            *max_sum = current_split ;
        }
        return node->val + max(left ,  right );
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN ;
        dfs(root , &max_sum);
        return max_sum ;
    }
};