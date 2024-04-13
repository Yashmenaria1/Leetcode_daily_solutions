class Solution {
public:
    int maxAreaHistogram(vector<int>& heights){
        heights.push_back(0);
        int area = 0, n = heights.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int h = heights[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                area = max(area, h*(right-left-1));
            }
            st.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = -1;
        vector<int> heights(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            int area = maxAreaHistogram(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
