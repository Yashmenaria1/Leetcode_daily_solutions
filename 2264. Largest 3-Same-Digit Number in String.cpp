class Solution {
public:
    string largestGoodInteger(string num) {
        char res = 0;
        for(int i = 0; i < num.size(); ++i)
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
                res = max(res, num[i]);
        return res == 0 ? "" : string(3, res);
    }
};


class Solution {
public:
    string largestGoodInteger(string num) {
    vector<string> arr = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
        for(auto s : arr){
            if(num.find(s) != -1){
                return s;
            }
        }
        return "";
    }
};
