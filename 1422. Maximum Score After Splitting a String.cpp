class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, mx = INT_MIN;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') zeros++; 
            else ones++;
            if(i != s.size() - 1)
                mx = max(zeros - ones, mx);
        }
        return mx + ones;
    }
};
