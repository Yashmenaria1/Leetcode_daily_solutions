class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[index] == t[i]) {
                index++;
            }
        }
        return index == s.size();
    }
};
