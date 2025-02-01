class Solution {
public:
    int maxScore(string s) {
        int size = s.length();
        int score = 0;

        for (int i = 0; i < size - 1; i++) {
            int left = 0, right = 0;

            for (int j = 0; j <= i; j++) {
                if (s[j] == '0')
                    left++;
            }

            for (int k = size - 1; k > i; k--) {
                if (s[k] == '1')
                    right++;
            }

            score = max(score, left + right);
        }
        return score;
    }
};