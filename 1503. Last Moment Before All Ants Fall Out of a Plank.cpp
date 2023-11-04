class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0;
        int minRight = n;

        for (int l : left) {
            maxLeft = max(maxLeft, l);
        }

        for (int r : right) {
            minRight = min(minRight, r);
        }

        return max(maxLeft, n - minRight);
    }
};
