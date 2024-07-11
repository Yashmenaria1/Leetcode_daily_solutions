class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        vector<int> v;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                v.push_back(res.length());
            }
            else if( s[i] == ')'){
                int j = v.back();
                v.pop_back();
                reverse(res.begin()+j, res.end());
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};
