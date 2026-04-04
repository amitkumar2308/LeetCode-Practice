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
    void dfs(TreeNode* node, int remaining,vector<int> &track,vector<vector<int>>&res){
         track.push_back(node->val);

         remaining = remaining - node->val;

         if(!node->left && !node->right && remaining==0){
            res.push_back(track);
         }
         if(node->left) dfs(node->left,remaining,track,res);
         if(node->right) dfs(node->right,remaining,track,res);

         track.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if(!root) return {};

        vector<int>track;
        vector<vector<int>>res;

        dfs(root,targetSum,track,res);
        return res;

        
    }
};