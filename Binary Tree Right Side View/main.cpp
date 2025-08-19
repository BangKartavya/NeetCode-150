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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> result;
            unordered_map<int, int> mp;

            if(!root) return result;

            queue<TreeNode*> q;
            q.push(root);
            int lvl = 0;

            while(!q.empty()) {
                int siz = q.size();
                while(siz--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    mp[lvl] = curr->val;

                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                lvl++;
            }

            for(int i = 0; i < lvl; i++) {
                result.push_back(mp[i]);
            }

            return result;
        }
};
