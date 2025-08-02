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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root == NULL){
            return result;
        }

        

        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            int n = q.size();
            TreeNode* node = NULL;

            for(int i = 0; i<n; i++){
                node = q.front();
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }

                if(i == n-1){
                    result.push_back(node->val);
                }
            }
        }

        return result;
    }
    
};