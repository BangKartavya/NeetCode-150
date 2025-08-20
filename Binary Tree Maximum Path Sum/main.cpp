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
    private:
        int maxi = INT_MIN;

        int dfs(TreeNode* root) {
            if(!root) return 0;

            int left = max(dfs(root->left), 0);
            int right = max(dfs(root->right), 0);

            maxi = max(maxi, root->val + left + right);

            return root->val + max(left, right);
        }

    public:
        int maxPathSum(TreeNode* root) {
            dfs(root);

            return maxi;
        }
};
