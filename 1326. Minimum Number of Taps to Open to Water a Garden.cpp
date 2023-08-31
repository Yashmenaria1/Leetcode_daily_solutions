class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n + 1, 0);
        for(int i = 0; i < ranges.size(); ++i) {
            if(ranges[i] == 0) continue;
            int left = max(0, i - ranges[i]);
            arr[left] = max(arr[left], i + ranges[i]);
        }
        
        int end = 0, max_go = 0, count = 0;
        for(int i = 0; i <= n; ++i) {
            if(i > end) {
                if(max_go <= end) return -1;
                end = max_go;
                ++count;
            }
            max_go = max(max_go, arr[i]);
        }
        
        return count + (end < n);
    }
};
