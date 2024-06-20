class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1, high = position[position.size() - 1] - position[0], ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, m, position)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool isPossible(int gap, int magnets, std::vector<int>& position) {
        int count = 1;
        int i = 0, j = 0, n = position.size();
        while (j < n) {
            int nextPos = position[i] + gap;
            while (j < n && position[j] < nextPos)
                j++;

            if (j < n) {
                count++;
                i = j;
            }

        }
        return count >= magnets;
    }
};
