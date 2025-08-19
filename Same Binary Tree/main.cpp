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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(!p && !q) return true;

            if((!p && q) || (p && !q) || (p->val != q->val)) return false;

            if((!p->left && q->left) || (!p->right && q->right) || (p->left && !q->left) || (p->right && !q->right)) return false;

            if(p->left) {
                if(p->left->val != q->left->val) return false;
            }
            if(p->right) {
                if(p->right->val != q->right->val) return false;
            }

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
};
