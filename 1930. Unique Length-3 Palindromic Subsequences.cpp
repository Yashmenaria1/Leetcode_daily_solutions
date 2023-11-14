class Solution {
public:
    int countPalindromicSubsequence(string str) {
        vector<pair<int, int> > subSequences(26, {-1, -1} );
        int n = str.length(); 
        
        for (int i = 0 ; i < n ; i++ ){
            if (subSequences[str[i] - 'a'].first == -1 ) 
                subSequences[str[i] - 'a'].first = i;
            else 
                subSequences[str[i] - 'a'].second = i; 
        }
        
        int res = 0 ;
        for (int i = 0 ; i < 26 ; i++ ){
            if (subSequences[i].second != -1 ){ 
                unordered_set<char> s;
                
                for (int x = subSequences[i].first + 1 ; x < subSequences[i].second ; x++ )
                    s.insert(str[x]);
                res += static_cast<int>(s.size());
            }
        }
        return res;
    }
};
