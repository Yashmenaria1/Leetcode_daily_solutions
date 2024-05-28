class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int diff = 0;
        int start = 0;
        int maxLength = 0;
        for (int end = 0; end < s.length(); end++) {
            diff += abs(s[end] - t[end]);
            while (diff > maxCost) {
                diff -= abs(s[start] - t[start]);
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
