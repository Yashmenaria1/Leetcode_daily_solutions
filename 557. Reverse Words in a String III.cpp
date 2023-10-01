class Solution {
public:
    string reverseWords(string s) {
        stringstream stringStream(s);
        string temp,ans;
        while(stringStream>>temp){
            reverse(temp.begin(),temp.end());
            ans+= (temp+" ");
        }
        
        return ans.substr(0,ans.size()-1);
    }
};
