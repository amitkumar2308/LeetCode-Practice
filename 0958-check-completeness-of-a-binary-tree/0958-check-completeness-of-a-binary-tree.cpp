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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
    

    queue<TreeNode*> q;
    q.push(root);
    bool end = false;

    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();

        if(current == nullptr){
            end = true;
        }else {
            if(end) return false;
            q.push(current->left);
            q.push(current->right);
        }
    }
    return true;
    }
};