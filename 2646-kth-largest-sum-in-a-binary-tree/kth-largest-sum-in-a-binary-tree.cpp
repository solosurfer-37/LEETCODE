/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

int compare(const void* a, const void* b) {
    long long int1 = *(long long*)a;
    long long int2 = *(long long*)b;
    return (int2 > int1) - (int2 < int1);
}
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sums[100000];
        int count = 0;
        TreeNode* q[100000];
        int head = 0, tail = 0;
        q[tail++] = root;
        while(head < tail) {
            int size = tail - head; 
            long long current = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q[head++];
                current += node->val;
                if(node->left) q[tail++] = node->left;
                if(node->right) q[tail++] = node->right;
            }
            sums[count++] = current; 
        }
        if(k > count) return -1;
        qsort(sums, count, sizeof(long long), compare);
        return sums[k-1];
    }
};