class Solution {
public:
    bool isPalin(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void findPalindrome(int curr, string& s, vector<string>& valid,
                        vector<vector<string>>& all) {
        if (curr == s.length()) {
            all.push_back(valid);
            return;
        }

        for (int i = curr; i < s.length(); i++) {
            if (isPalin(s, curr, i)) {
                valid.push_back(s.substr(curr, i - curr + 1));
                findPalindrome(i + 1, s, valid, all);
                valid.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> valid;
        vector<vector<string>> all;
        int size = s.length();
        findPalindrome(0, s, valid, all);
        return all;
    }
};