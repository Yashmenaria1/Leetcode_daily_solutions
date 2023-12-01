class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1 = "", str2 = "";
        
        for( auto w1 : word1 ){
            str1 += w1;
        }
        
        for( auto w2 : word2 ){
            str2 += w2;
        }
        
        return str1 == str2;
    }
};
