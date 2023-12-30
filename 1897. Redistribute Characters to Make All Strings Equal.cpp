class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {};
        for(auto w : words){
            for(auto ch : w)
                cnt[ch - 'a']++;
        }
        
        for(auto f : cnt)
            if(f % words.size() != 0)
                return false;
            return true;
    }
};
