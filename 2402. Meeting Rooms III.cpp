class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int cnt[101] = {};
        sort(begin(meetings), end(meetings));
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i = 0; i < n; ++i)
            pq.push({meetings[0][0], i});
        for (auto &m : meetings) {
            while (pq.top().first < m[0]) {
                pq.push({m[0], pq.top().second});
                pq.pop();
            }
            auto [start, room] = pq.top(); pq.pop();
            pq.push({start + m[1] - m[0], room});
            ++cnt[room];
        }
        return max_element(begin(cnt), end(cnt)) - begin(cnt);
    }
};
