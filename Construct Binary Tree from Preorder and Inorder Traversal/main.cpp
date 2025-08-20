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
    int pre = 0;
    int ino = 0;

    vector<int> preorder;
    vector<int> inorder;

    TreeNode* dfs(int limit) {
        if(pre >= preorder.size()) return nullptr;

        if(inorder[ino] == limit) {
            ino++;
            return nullptr;
        }

        TreeNode* head = new TreeNode(preorder[pre++]);
        head->left = dfs(head->val);
        head->right = dfs(limit);

        return head;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;

        return dfs(INT_MAX);
    }
};
