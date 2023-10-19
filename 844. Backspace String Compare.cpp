class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return createStack(s) == createStack(t);
    }
private:
    stack<char> createStack(string s) {
        stack<char> ans;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '#')
                ans.push(s[i]);
            else if (!ans.empty())
                ans.pop();

        return ans;
    }
};
