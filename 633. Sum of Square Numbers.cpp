class Solution {
public:
    bool judgeSquareSum(int c) {
        long long s = 0, e = sqrt(c) ;

        while(s<=e){
            if((s*s + e*e) == c){
                return true;
            }
            else if((s*s + e*e) > c){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};
