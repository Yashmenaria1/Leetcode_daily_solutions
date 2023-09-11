class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groupsOfPeople;
        map<int, vector<int>> groups;

        for (int i = 0; i < groupSizes.size(); i++) {
            int desiredGroupSize = groupSizes[i];

            groups[desiredGroupSize].push_back(i);
            if (groups[desiredGroupSize].size() == desiredGroupSize) {
                groupsOfPeople.emplace_back(move(groups[desiredGroupSize]));
                groups[desiredGroupSize].clear();
            }
        }
        return groupsOfPeople;
    }
};
