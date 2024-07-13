class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> st;
        vector<int> sorted_indices(positions.size());
        iota(sorted_indices.begin(), sorted_indices.end(), 0);
        
        sort(sorted_indices.begin(), sorted_indices.end(), [&positions](int i, int j) {
            return positions[i] < positions[j];
        });

        for (int i : sorted_indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && healths[st.top()] < healths[i]) {
                    healths[i] -= 1;
                    healths[st.top()] = 0;
                    st.pop();
                }
                if (!st.empty()) {
                    if (healths[st.top()] == healths[i]) {
                        healths[st.top()] = 0;
                        st.pop();
                    } else {
                        healths[st.top()] -= 1;
                    }
                    healths[i] = 0;
                }
            }
        }

        vector<int> res;
        for (int health : healths) {
            if (health > 0) {
                res.push_back(health);
            }
        }
        return res;
    }
};
