class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result += extendPalindrome(s, i, i); 
            result += extendPalindrome(s, i, i + 1); 
        }
        return result;
    }
    
    int extendPalindrome(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left--] == s[right++]) {
            count++;
        }
        return count;
    }
};
