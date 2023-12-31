class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int last[26] = {0}, ans = -1;
        for(int i = 0; i < s.size(); ++i) 
            last[s[i] - 'a'] = i;
        for(int i = 0; i < s.size(); ++i) 
            ans = max(ans, last[s[i] - 'a'] - i - 1);
        return ans;
    }
};
