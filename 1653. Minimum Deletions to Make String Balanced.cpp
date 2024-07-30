class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, count = 0;
        for(char& x:s){
            if(x == 'a'){
                res = min(++res, count);
            }
            if(x == 'b'){
                count++;
            }
        }
        return res;
    }
};
