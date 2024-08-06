class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first; 
        return a.second > b.second;   
    }
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(char ch:word){
            mp[ch]++;
        }
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());
        sort(freqVec.begin(), freqVec.end(), compare);
        int count = 0, ans = 0;
        for(auto& f:freqVec){
            count++;
            if(count>24){
                ans += 4*f.second;
            }
            else if(count>16){
                ans += 3*f.second;
            }
            else if(count>8){
                ans += 2*f.second;
            }
            else{
                ans += f.second;
            }
        }
        return ans;
    }
};
