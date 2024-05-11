class Solution {
public:
    double mincostToHireWorkers(vector<int> quality, vector<int> wage, int K) {
        vector<vector<double>> workers;
        for (int i = 0; i < quality.size(); ++i){
            workers.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
        }
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return res;
    }
};
