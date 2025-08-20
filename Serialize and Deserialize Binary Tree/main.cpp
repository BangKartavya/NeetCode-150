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

class Codec {
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);

            string result;

            while(!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();

                if(!curr) {
                    result += ("N,");
                } else {
                    result += to_string(curr->val) + ",";
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            return result;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            string val;
            stringstream ss(data);

            getline(ss, val, ',');

            if(val == "N") return nullptr;

            TreeNode* root = new TreeNode(stoi(val));
            queue<TreeNode*> q;
            q.push(root);

            while(getline(ss, val, ',')) {
                TreeNode* curr = q.front();
                q.pop();

                if(val != "N") {
                    curr->left = new TreeNode(stoi(val));
                    q.push(curr->left);
                }
                getline(ss, val, ',');

                if(val != "N") {
                    curr->right = new TreeNode(stoi(val));
                    q.push(curr->right);
                }
            }

            return root;
        }
};
