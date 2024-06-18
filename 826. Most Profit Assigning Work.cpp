class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair <int, int>>jobs;
        int n = worker.size();
        int profits = 0, s = 0, maxi = 0;
        sort(worker.begin(), worker.end());

        for(int i = 0; i<n; i++){
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for(int &w : worker){
            while(s < n && w >= jobs[s].first){
                maxi = max(jobs[s++].second, maxi);
            }
            profits += maxi;
        }
        return profits;
    }
};
