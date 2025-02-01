class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr)
            return 0;

        int leftMax = max(0, maxGain(node->left, maxSum));
        int rightMax = max(0, maxGain(node->right, maxSum));

        int CurrentPathSum = node->val + leftMax + rightMax;

        maxSum = max(maxSum, CurrentPathSum);

        return node->val + max(leftMax,rightMax);
    }
};