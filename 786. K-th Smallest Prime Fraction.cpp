class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        int N = arr.size();
        while (true) {
            double m = (l + r) / 2;
            int cur = 0, total = 0, p = 0, q = 1;
            for (int i = 0, j = 0; i < N; ++i) {
                while (j < N && arr[i] > m * arr[j]) ++j;
                cur += N - j;
                if (j < N && p * arr[j] < q * arr[i]) {
                    p = arr[i];
                    q = arr[j];
                }
            }
            if (cur > k) r = m;
            else if (cur < k) l = m;
            else return {p, q};
        }
    }
};
