class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int, long long> freq;
        int size = nums.size();
        long long totalPairs = (long long)size * (size - 1) / 2;

        long long goodPairs = 0;

        for (int i = 0; i < size; i++) {
            int value = i - nums[i];
            goodPairs += freq[value];
            freq[value]++;
        }

        return totalPairs - goodPairs;
    }
};