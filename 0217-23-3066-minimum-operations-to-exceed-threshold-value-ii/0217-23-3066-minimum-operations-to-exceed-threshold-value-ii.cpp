class Solution {
public:
    long long addNum(long long a, long long b) {
        long long temp = (min(a, b) * 2) + max(a, b);
        return temp;
    }
    int minOperations(vector<int>& nums, int k) {
         priority_queue<long long, vector<long long>, greater<long long>> queue; // 1 2 3 10 11
        int size = nums.size();

        for (int num : nums) {
            queue.push(num);
        }

        int counter = 0;
        while (!queue.empty() && queue.top()<k) {
            long long first = queue.top();
            queue.pop();

            if(queue.empty()) break;

            long long second = queue.top();
            queue.pop();

            long long newNum = addNum(first, second);
            queue.push(newNum);
            counter++;
        }

        return counter;
    }
};