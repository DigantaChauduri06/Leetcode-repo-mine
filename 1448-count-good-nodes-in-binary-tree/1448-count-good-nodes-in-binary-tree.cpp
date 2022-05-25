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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int rVal = root->val;
        int left = countGood(root->left, rVal, rVal);
        int right = countGood(root->right, rVal, rVal);
        return  left + right + 1;
    }
private:
    int countGood(TreeNode *node, int rootVal, int mxVal) {
        if (!node) return 0;
        mxVal = max(mxVal, node->val);
        return (node->val >= mxVal) + countGood(node->left, mxVal, mxVal) + countGood(node->right, mxVal, mxVal);
    }
};