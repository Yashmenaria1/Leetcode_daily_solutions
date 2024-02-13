class Solution {
public:
    string firstPalindrome(vector<string>& words) {
    for (auto &w : words)
        if (w == string(rbegin(w), rend(w)))
            return w;
    return {};
    }
};
