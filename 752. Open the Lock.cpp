class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;
        if (target == "0000")
            return 0;

        int ans = 0;
        queue<string> q{{"0000"}};
        unordered_set<string> seen{"0000"};

        while (!q.empty()) {
            ++ans;
            for (int sz = q.size(); sz > 0; --sz) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    char original = word[i];
                    word[i] = (word[i] - '0' + 1) % 10 + '0';
                    if (word == target)
                        return ans;
                    if (!dead.count(word) && !seen.count(word)) {
                        q.push(word);
                        seen.insert(word);
                    }
                    word[i] = (original - '0' + 9) % 10 + '0';
                    if (word == target)
                        return ans;
                    if (!dead.count(word) && !seen.count(word)) {
                        q.push(word);
                        seen.insert(word);
                    }
                    word[i] = original;
                }
            }
        }
        return -1;
    }
};
