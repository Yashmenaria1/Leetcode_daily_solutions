class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int totalMoves = 0;
        for(int i = 0; i<seats.size(); i++){
            totalMoves += abs(seats[i] - students[i]);
        }
        return totalMoves;
    }
};
