class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        vector<int> prefixXOR(n+1, 0);
        for(int i = 0; i<n; i++){
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (prefixXOR[i] == prefixXOR[j]) {
                    count += (j - i - 1);
                }
            }
        }
        return count;
    }
};
