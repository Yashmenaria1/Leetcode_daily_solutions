class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, direction = 0, maxDist = 0;
        set<pair<int, int>> obstacleSet;

        for(const auto& ob:obstacles){
            obstacleSet.insert({ob[0], ob[1]});
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int command:commands){
            if(command == -1){
                direction = (direction+1)%4;
            }
            else if(command == -2){
                direction = (direction+3)%4;
            }
            else{
                int steps = command;
                while(steps){
                    int newx = x+dir[direction].first;
                    int newy = y+dir[direction].second;

                    if(obstacleSet.find({newx, newy}) != obstacleSet.end()){
                        break;
                    }

                    x = newx;
                    y = newy;
                    maxDist = max(maxDist, x*x + y*y);
                    steps--;
                }
            }
        }
        return maxDist;
    }
};
