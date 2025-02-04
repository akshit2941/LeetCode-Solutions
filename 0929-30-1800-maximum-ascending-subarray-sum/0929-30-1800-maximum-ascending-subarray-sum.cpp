class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return nums[0];

        int maxSum = nums[0];
        int currMax = nums[0];

        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                currMax += nums[i];
            } else {
                currMax = nums[i];
            }
            maxSum = max(maxSum, currMax);
        }
        return maxSum;
    }
};