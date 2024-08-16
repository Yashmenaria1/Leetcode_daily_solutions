//Brute force
//TC: O(N^2), SC: O(n)
//TLE (135/136) Test Case Passed
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> maxD, minD;
        for(int i = 0; i<arrays.size(); i++){
            int mini = arrays[i][0];
            minD.push_back(mini);
            int n = arrays[i].size();
            int maxi = arrays[i][n-1];
            maxD.push_back(maxi);
        }
        int ans = 0;
        for(int i = 0; i<minD.size(); i++){
            for(int j = 0; j<minD.size(); j++){
                if(i == j) continue;
                ans = max(ans, abs(maxD[i]-minD[j]));
            }
        }
        return ans;
    }
};

//Optimised
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int ans = 0;
        for(int i = 1; i<arrays.size(); i++){
            ans = max(ans, abs(mini - arrays[i].back()));
            ans = max(ans, abs(maxi - arrays[i][0]));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        return ans;
    }
};
