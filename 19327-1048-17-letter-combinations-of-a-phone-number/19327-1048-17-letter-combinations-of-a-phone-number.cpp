class Solution {
private:
    void findCombination(string& digits, unordered_map<char, string>& mp,
                         int index, string current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = mp[digits[index]];
        for (char letter : letters) {
            findCombination(digits, mp, index + 1, current + letter, result);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> results;

        findCombination(digits, mp, 0, "", results);
        return results;
    }
};
// 23 -> abc, def
//  one loop -> access both string iterate 1st letter of a string to other
//  string a -> def then b-> def then c->def
// keep adding the generated in vector