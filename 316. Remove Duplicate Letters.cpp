class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26,0)  , visited_char(26,0);
        
        string res = "";
        int n = s.size();
        
        for(int i = 0; i<n; ++i)
            count[s[i] - 'a']++;
        
        for(int i = 0; i<n; ++i)
        {
            count[s[i] - 'a']--;
            
            if(!visited_char[s[i]- 'a'])
            {
                while(res.size() > 0 && res.back() > s[i] && count[res.back() - 'a'] > 0)
                {
                    visited_char[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += s[i];
                visited_char[s[i] - 'a'] = 1;
            }
        }
        return res;
    }
};
