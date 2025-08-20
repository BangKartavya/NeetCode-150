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
        vector<int> a;

        void inOrder(TreeNode* root) {
            if(!root) return;

            inOrder(root->left);
            a.push_back(root->val);
            inOrder(root->right);
        }

    public:
        bool isValidBST(TreeNode* root) {
            inOrder(root);

            if(a.empty()) return true;

            int n = a.size();

            for(int i = 0; i < n - 1; i++) {
                if(a[i] >= a[i + 1]) return false;
            }

            return true;
        }
};
