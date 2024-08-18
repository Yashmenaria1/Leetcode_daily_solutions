//1st Approach
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        int i2 = 0, i3 = 0, i5 = 0;
        int ugly1 = 2, ugly2 = 3, ugly3 = 5;
        
        while(ans.size()<n){
            int mini = min(ugly1, min(ugly2, ugly3));
            ans.push_back(mini);
            if(mini == ugly1){
                i2++;
                ugly1 = 2*ans[i2];
            }
            if(mini == ugly2){
                i3++;
                ugly2 = 3*ans[i3];
            }
            if(mini == ugly3){
                i5++;
                ugly3 = 5*ans[i5];
            }
        }
        return ans[n-1];
    }
};

//2nd Approach
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        
        for(int i = 1; i<n; i++){
            int twoMul = dp[i2]*2;
            int threeMul = dp[i3]*3;
            int fiveMul = dp[i5]*5;

            dp[i] = min(twoMul, min(threeMul, fiveMul));

            if(dp[i] == twoMul) i2++;
            if(dp[i] == threeMul) i3++;
            if(dp[i] == fiveMul) i5++;
        }
        
        return dp[n-1];
    }
};
