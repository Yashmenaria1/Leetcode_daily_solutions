class Solution {
public:
    int getWinner(vector<int>& A, int k) {
    int curr = A[0], win = 0;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] > curr) {
            curr = A[i];
            win = 0;
        }
        if (++win == k) break;
    }
    return curr;
    }
};
