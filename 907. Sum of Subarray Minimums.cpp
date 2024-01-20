class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long res = 0;
        stack<int> stack;
        const long long M = 1e9 + 7;
        stack.push(-1);
        
        for (int i2 = 0; i2 < arr.size() + 1; i2++) {
            int currVal = (i2 < arr.size()) ? arr[i2] : 0;
            
            while (stack.top() != -1 && currVal < arr[stack.top()]) {
                int index = stack.top();
                stack.pop();
                int i1 = stack.top();
                int left = index - i1;
                int right = i2 - index;
                long long add = (left * right * static_cast<long long>(arr[index])) % M;
                res += add;
                res %= M;
            }
            
            stack.push(i2);
        }
        
        return static_cast<int>(res);
    }
};
