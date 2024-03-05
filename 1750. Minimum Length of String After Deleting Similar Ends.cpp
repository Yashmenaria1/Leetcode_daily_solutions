class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1, character = 0;
        while (left < right && s[left] == s[right]) {
            character = s[left];
            while (left < right && s[left] == character)
                ++left;
            while (left < right && s[right] == character)
                --right;
        }
        return s[left] == character ? 0 : right - left + 1;
    }
};
