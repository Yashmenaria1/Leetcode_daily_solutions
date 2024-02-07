class Solution {
public:
    string frequencySort(const string& s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        for (char c : s)  cnt[c] += 1;
        
        vector<vector<char>> bucket(n+1);
        for (auto [c, f] : cnt)
            bucket[f].push_back(c);
        
        string ans;
        for (int freq = n; freq >= 1; --freq)
            for (char c : bucket[freq]) 
                ans.append(freq, c);
        return ans;
    }
};
