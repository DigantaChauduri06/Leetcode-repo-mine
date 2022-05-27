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
    vector<string> binaryTreePaths(TreeNode* root) {
        string op = "";
        vector<string> ans;
        fun(root, ans, op);
        return ans;
    }
private:
    void fun(TreeNode *root, vector<string> &ans, string op) {
        if (!root) return;
        if (!root->left && !root->right) {
            op.append(to_string(root->val));
            ans.push_back(op);
            return;
        }
        op.append(to_string(root->val) + "->");
        fun(root->left, ans, op);
        fun(root->right, ans, op);
    }
};