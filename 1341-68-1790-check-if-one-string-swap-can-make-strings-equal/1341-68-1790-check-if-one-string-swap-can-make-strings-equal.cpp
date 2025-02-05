class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        int size = s1.length();
        int diff = 0;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < size; i++) {
            if (s1[i] != s2[i]) {
                diff++;
                freq1[s1[i] - 'a']++;
                freq2[s2[i] - 'a']++;
            }
        }

        if (freq1 == freq2) {
            if (diff > 1 && diff <= 2)
                return true;
            else
                return false;
        } else
            return false;
    }
};