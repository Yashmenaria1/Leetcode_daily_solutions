class Solution {
public:
    long long mod =  1e9 + 7;
    long long fun(int n){
        if (n==1) return 1;
        long long m = n;
        return (m*(2*m-1)*countOrders(m-1))%mod;
    }
    int countOrders(int n) {
        return fun(n);
    }
};
