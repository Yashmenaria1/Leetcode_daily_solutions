class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> res;
        int l = to_string(low).length();
        int h = to_string(high).length();
        
        for(int i = l; i <= h; i++){
            for(int j = 0; j < 10 - i; j++){
                int num = stoi(digits.substr(j, i));
                if(num >= low && num <= high) res.push_back(num);
            }
        }
        return res;
    }
};
