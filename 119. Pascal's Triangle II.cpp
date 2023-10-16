class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        long long temp = 1; 
        ans[0] = ans[rowIndex] = 1;
        
        for (int i = 1, up = rowIndex, down = 1; i <= rowIndex; i++, up--, down++) {
            temp = temp * up / down;
            ans[i] = static_cast<int>(temp);
        }
        
        return ans;
    }
};
