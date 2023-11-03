class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int currNum = 1;

        for(int i=0; i<target.size(); i++) {
            while(currNum!=target[i]) {
                res.push_back("Push");
                res.push_back("Pop");
                currNum++;
            }
            res.push_back("Push");
            currNum++;
        }
        return res;
    }
};
