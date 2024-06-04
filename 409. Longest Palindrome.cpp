class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        if(s.length() == 1) return 1;
        unordered_map<char, int> m;
        for(auto& ch: s){
            m[ch]++;
        }
        bool oddChar = false;
        for(auto& pair : m){
            if(pair.second%2 == 0){
                count +=pair.second;
            }else{
                count += pair.second -1;
                oddChar = true;
            }
        }
        if(oddChar){
            count++;
        }
        return count;
    }
};
