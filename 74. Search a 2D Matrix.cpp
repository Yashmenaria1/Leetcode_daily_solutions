class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty())
      return false;

    const int row = matrix.size();
    const int col = matrix[0].size();
    int left = 0;
    int right = row * col;

    while (left < right) {
      const int mid = left + (right - left) / 2;
      const int i = mid / col;
      const int j = mid % col;
      if (matrix[i][j] == target)
        return true;
      if (matrix[i][j] < target)
        left = mid + 1;
      else
        right = mid;
    }

    return false;
  }
};
