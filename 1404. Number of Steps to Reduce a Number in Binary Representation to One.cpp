class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        reverse(s.begin(), s.end());
        while (s.size() > 1) {
            if (s[0] == '1') {
                int i = 0;
                while (i < s.size() && s[i] == '1') {
                    s[i] = '0';
                    i++;
                }
                if (i == s.size()) {
                    s.push_back('1');
                } else {
                    s[i] = '1';
                }
            } else {
                s.erase(s.begin());
            }
            count++;
        }
        return count;
    }
};
