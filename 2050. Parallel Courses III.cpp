class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> dependencyGraph(n);

        for (const vector<int>& relation : relations) {
            int prerequisiteCourse = relation[0] - 1;
            int currentCourse = relation[1] - 1;
            dependencyGraph[prerequisiteCourse].push_back(currentCourse);
        }

        vector<int> minimumTimeMemo(n, -1);

        function<int(int)> calculateMinimumTime = [&](int currentCourse) {
            if (minimumTimeMemo[currentCourse] != -1) {
                return minimumTimeMemo[currentCourse];
            }

            if (dependencyGraph[currentCourse].empty()) {
                minimumTimeMemo[currentCourse] = time[currentCourse];
                return minimumTimeMemo[currentCourse];
            }

            int maxPrerequisiteTime = 0;
            for (int prerequisite : dependencyGraph[currentCourse]) {
                maxPrerequisiteTime = max(maxPrerequisiteTime, calculateMinimumTime(prerequisite));
            }

            minimumTimeMemo[currentCourse] = maxPrerequisiteTime + time[currentCourse];
            return minimumTimeMemo[currentCourse];
        };

        int overallMinimumTime = 0;
        for (int currentCourse = 0; currentCourse < n; currentCourse++) {
            overallMinimumTime = max(overallMinimumTime, calculateMinimumTime(currentCourse));
        }

        return overallMinimumTime;
    }
};
