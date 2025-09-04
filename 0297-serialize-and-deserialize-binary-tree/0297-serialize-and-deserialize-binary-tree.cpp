/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string val;
        for(int i=0; i<data.size(); i++){
            if(data[i]==','){
                q.push(val);
                val.clear();
            }else{
                val.push_back(data[i]);
            }
        }
    return buildTree(q);
    }
    private:
       TreeNode* buildTree(queue<string> &q){
        string val = q.front(); q.pop();
        if(val == "null") return NULL;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(q);
        node->right = buildTree(q);
        return node;
       }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));