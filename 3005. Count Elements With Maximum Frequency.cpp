class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int maxi = 0;
        for (auto x : freq) {
            if (x.second > maxi)
                maxi = x.second;
        }

        int res = 0;
        for (auto x : freq) {
            if (x.second == maxi) 
                res += maxi;
        }
        return res;
    }
};
