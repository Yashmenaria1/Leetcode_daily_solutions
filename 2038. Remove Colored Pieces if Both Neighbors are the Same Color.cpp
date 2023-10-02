class Solution {
public:
    bool winnerOfGame(string colors) {
        int alicePlays = 0, bobPlays = 0; 

        for (int i = 1; i < colors.size() - 1; i++) {
            char currColor = colors[i];
            char prevColor = colors[i - 1];
            char nextColor = colors[i + 1];

            if (currColor == 'A' && prevColor == 'A' && nextColor == 'A')
                alicePlays++; 

            else if (currColor == 'B' && prevColor == 'B' && nextColor == 'B')
                bobPlays++;
        }

        return alicePlays > bobPlays;
    }
};
