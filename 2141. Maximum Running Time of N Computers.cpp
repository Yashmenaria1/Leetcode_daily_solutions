class Solution {
public:
    bool fun(vector<int>& a, long long x, long long k){
        long long val = x*k;
        for(int i=0; i<a.size(); i++){
            val -= min((long long)a[i],k);
        }
        return val <= 0;
    }
    long long maxRunTime(int n, vector<int>& a) {
        long long sum = 0;
        for(auto i : a){
            sum += i;
        }
        long long ans = 0;
        long long l = 0, r = sum;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(fun(a,n,mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
