class Solution {
public:
    bool checkValidString(string s) {
        int minOpenParentheses = 0, maxOpenParentheses = 0;
        for (char c : s) {
            if (c == '(')
                maxOpenParentheses++, minOpenParentheses++;
            if (c == ')')
                maxOpenParentheses--, minOpenParentheses = max(minOpenParentheses - 1, 0);
            if (c == '*')
                maxOpenParentheses++, minOpenParentheses = max(minOpenParentheses - 1, 0);
            if (maxOpenParentheses < 0) return false;
        }
        return minOpenParentheses == 0;
    }
};
