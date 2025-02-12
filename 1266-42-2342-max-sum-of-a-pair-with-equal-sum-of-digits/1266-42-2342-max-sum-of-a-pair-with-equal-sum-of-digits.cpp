class Solution {
public:
    int sumOfDigit(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxPairSum = -1;

        for (int num : nums) {
            int digitSum = sumOfDigit(num);

            if (digitSumMap.find(digitSum) != digitSumMap.end()) {
                maxPairSum = max(maxPairSum, digitSumMap[digitSum] + num);
            }
            digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
        }
        return maxPairSum;
    }
};