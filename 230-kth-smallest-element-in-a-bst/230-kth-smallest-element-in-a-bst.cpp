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
    int k;
    int ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        fun(root);
        return ans;
    }
private:
    void fun(TreeNode *root) {
        if (!root) {
            return;
        }
        fun(root->left);
        k--;
        if (k==0) {
            ans = root->val;
            return;
        }
        fun(root->right);
    }
};