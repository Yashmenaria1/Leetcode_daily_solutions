class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> s;
        for (int i = 0; i < heights.size() - 1; i++) {
            int d = heights[i + 1] - heights[i];
            if (d > 0)
                s.insert(heights[i + 1] - heights[i]);
            if (s.size() > ladders) {
                bricks -= *s.begin();
                s.erase(s.begin());
                if (bricks < 0) return i;
            }
        }
        return heights.size() - 1;
    }
};
