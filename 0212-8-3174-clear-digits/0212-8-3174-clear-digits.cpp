class Solution {
public:
    string clearDigits(string s) {
        int size = s.length();
        stack<char> st;

        for (int i = 0; i < size; i++) {
            if (!isdigit(s[i])) {
                st.push(s[i]);
            } else{
                st.pop();
            }
        }

        string ans ="";
        while(!st.empty()){
            char temp = st.top();
            st.pop();
            ans += temp;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};