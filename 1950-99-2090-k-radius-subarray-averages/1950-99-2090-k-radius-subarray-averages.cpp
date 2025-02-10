class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> values(size, -1);

        if (k == 0)
            return nums;
        if (2 * k + 1 > size)
            return values;

        long long sum = 0;
        for (int i = 0; i < 2 * k + 1; i++) {
            sum += nums[i];
        }

        for (int i = k; i < size - k; i++) {
            if (i > k) {
                sum += nums[i + k] - nums[i - k - 1];
            }
            values[i] = sum / (2 * k + 1);
        }
        return values;
    }
};