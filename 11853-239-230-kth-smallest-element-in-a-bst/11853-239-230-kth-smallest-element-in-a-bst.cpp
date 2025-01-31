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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> values;
        vector<int> sorted;
        if (root == nullptr) return NULL;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            values.push(current->val);
            q.pop();


            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }

        while(!values.empty()){
            sorted.push_back(values.top());
            values.pop();
        }

        int size = sorted.size();
        return sorted[size-k];

    }
};