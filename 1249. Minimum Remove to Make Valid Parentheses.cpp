class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> arr(s.begin(), s.end());
        int open = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(')
                open++;
            else if (arr[i] == ')') {
                if (open == 0)
                    arr[i] = '*';
                else
                    open--;
            }
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (open > 0 && arr[i] == '(') {
                arr[i] = '*';
                open--;
            }
        }

        int p = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != '*')
                arr[p++] = arr[i];
        }

        return string(arr.begin(), arr.begin() + p);
    }
};
