class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        if(k==0) return 0;
        sort(happiness.begin(), happiness.end(),greater<>());
        long long res = 0;
        int decremented = 0;
        for(int i = 0; i<k; ++i){
            res += max(0LL,static_cast<long long>(happiness[i]-decremented));
            ++decremented;
        }
        return res;
    }
};
