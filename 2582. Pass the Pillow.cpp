//Mathematical
class Solution {
public:
    int passThePillow(int n, int time) {
        int index = n - abs(n-1 - time%(2*n-2));
        return index;
    }
};

//2nd
class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1, start = 0, dir = 1;
        while(start<time){
            idx += dir;
            if(idx == n || idx == 1){
                dir = -dir;
            }
            start++;
        }
        return idx;
    }
};
