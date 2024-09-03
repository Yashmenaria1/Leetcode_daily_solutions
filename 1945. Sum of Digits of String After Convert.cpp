class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        
        for (char c : s) {
            int val = c - 'a' + 1;
            sum += (val / 10) + (val % 10);
        }
        
        while (k > 1) {
            sum = getDigitSum(sum);
            k--;
        }
        
        return sum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
