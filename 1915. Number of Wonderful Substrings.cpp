class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024);
        long long res = 0, mask = 0;
        count[0] = 1L;
        for (char& ch : word) {
            mask ^= 1 << (ch - 'a');
            res += count[mask]++;
            for (int i = 0; i < 10; ++i)
                res += count[mask ^ (1 << i)];
        }
        return res;
    }
};
