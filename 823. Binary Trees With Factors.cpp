class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        long ans = 0;
        unordered_map<int, long> m;
        for (int num : arr) {
            long ways = 1;
            double lim = sqrt(num);
            for (int j = 0, fA = arr[0]; fA <= lim; fA = arr[++j]) {
                if (num % fA != 0) continue;
                int fB = num / fA;
                if (m.find(fB) != m.end())
                    ways = (ways + m[fA] * m[fB] * (fA == fB ? 1 : 2)) % 1000000007;
            }
            m[num] = ways;
            ans = (ans + ways) % 1000000007;
        }
        return (int)ans;
    }
};
