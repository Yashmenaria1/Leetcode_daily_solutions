class Solution {
public:
    string decodeAtIndex(string encodedString, int k) {
        stack<long long> lengthsStack;
        lengthsStack.push(0); 

        for (size_t i = 0; i < encodedString.length(); ++i) {
            if (isdigit(encodedString[i])) {
                long long currentLength = lengthsStack.top() * (encodedString[i] - '0'); 
                lengthsStack.push(currentLength); 
            }
            else {
                long long currentLength = lengthsStack.top() + 1; 
                lengthsStack.push(currentLength); 
            }
        }

        size_t stackSize = lengthsStack.size();
        while (!lengthsStack.empty()) {
            k %= lengthsStack.top();
            stackSize--; 
            if (k == 0 && isalpha(encodedString[stackSize - 1])) {
                return string(1, encodedString[stackSize - 1]);
            }
            lengthsStack.pop(); 
        }
        return ""; 
    }
};
