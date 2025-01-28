class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long result = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign <= INT_MIN)
                return INT_MIN;
            if (result * sign >= INT_MAX)
                return INT_MAX;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};