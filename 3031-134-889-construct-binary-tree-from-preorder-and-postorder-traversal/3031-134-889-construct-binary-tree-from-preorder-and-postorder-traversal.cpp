class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        int preIndex = 0;

        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }

        return buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1,
                         postIndex);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder,
                        int& preIndex, int postStart, int postEnd,
                        unordered_map<int, int>& postIndex) {
        if (preIndex >= preorder.size() || postStart > postEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (postStart == postEnd)
            return root;

        int leftSubtreeRootIndex = postIndex[preorder[preIndex]];

        root->left = buildTree(preorder, postorder, preIndex, postStart,
                               leftSubtreeRootIndex, postIndex);
        root->right =
            buildTree(preorder, postorder, preIndex, leftSubtreeRootIndex + 1,
                      postEnd - 1, postIndex);

        return root;
    }
};