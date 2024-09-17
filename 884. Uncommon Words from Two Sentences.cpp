class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string str = s1 + " " + s2 + " ";
        string a = "";
        int i = 0;

        while(i<str.length()){
            if(str[i] != ' '){
                a += str[i];
            }
            else if(str[i] == ' ' || i==str.length()-1){
                mp[a]++;
                a = "";
            }
            i++;
        }

        for(auto it:mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
