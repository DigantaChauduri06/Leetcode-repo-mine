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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto fr = q.front();
                q.pop();
                if (fr->left) {
                    q.push(fr->left);
                }
                if (fr->right) {
                    q.push(fr->right);
                }
            }
            cnt++;
        }
        return cnt;
    }
};