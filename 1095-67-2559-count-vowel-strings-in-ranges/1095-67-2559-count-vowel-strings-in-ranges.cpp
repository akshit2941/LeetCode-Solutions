class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixCount(n, 0);

        for (int i = 0; i < n; i++) {
            string str = words[i];
            if (isVowel(str[0]) && isVowel(str[str.size() - 1])) {
                prefixCount[i] = (i == 0) ? 1 : prefixCount[i - 1] + 1;
            } else {
                prefixCount[i] = (i == 0) ? 0 : prefixCount[i - 1];
            }
        }
        vector<int> result;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int count = prefixCount[r] - (l > 0 ? prefixCount[l - 1] : 0);
            result.push_back(count);
        }

        return result;
    }
};