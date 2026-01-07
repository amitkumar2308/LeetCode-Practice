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
    long long maxProductResult = 0;
    long long totalSum = 0;
    const int MOD = 1e9 + 7;

    // Step 1: calculate total sum of the tree
    long long calcTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + calcTotalSum(root->left) + calcTotalSum(root->right);
    }

    // Step 2: compute max product while calculating subtree sums
    long long maxProductDFS(TreeNode* root) {
        if (!root) return 0;
        long long leftSum = maxProductDFS(root->left);
        long long rightSum = maxProductDFS(root->right);
        long long subTreeSum = root->val + leftSum + rightSum;
        // Update maximum product
        maxProductResult = max(maxProductResult, subTreeSum * (totalSum - subTreeSum));
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
         totalSum = calcTotalSum(root);
        maxProductDFS(root);
        return maxProductResult % MOD;
    }
};