class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {};
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (char ch : t) {
            cnt[ch - 'a']--;
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            result += abs(cnt[i]);
        }

        return result / 2;
    }
};
