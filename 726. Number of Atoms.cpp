class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        stack<map<string,int>> st;
        int i = 0, n = formula.length();
        while(i<n){
            char ch = formula[i];
            i++;
            if(ch == '('){
                st.push(mp);
                mp.clear();
            }
            else if(ch == ')'){
                int val = 0;
                while(i<n && isdigit(formula[i])){
                    val = val*10 + formula[i++]-'0';
                }
                if(val == 0) val = 1;
                if (!st.empty()) {
                    map<string, int> temp = mp;
                    mp = st.top();
                    st.pop();
                    for (const auto& pair : temp){
                        mp[pair.first] += pair.second * val;
                    }
                }
            }
            else {
                int start = i - 1;
                while (i < n && islower(formula[i])) i++;
                string s = formula.substr(start, i - start);
                int val = 0;
                while (i < n && isdigit(formula[i]))
                    val = val * 10 + formula[i++] - '0';
                if (val == 0) val = 1;
                mp[s] += val;
            }
        }
        string res;
        map<string, int> sortedMap(mp.begin(), mp.end());
        for (const auto& pair : sortedMap) {
            res += pair.first;
            if (pair.second > 1)
                res += to_string(pair.second);
        }
        return res;
    }
};
