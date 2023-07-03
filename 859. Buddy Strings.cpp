class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size();
        }

        int start = 0;
        int end = n - 1;

        while(start < end && s[start] == goal[start]){
            start++;
        }

        while(end >= 0 && s[end] == goal[end]){
            end--;
        }

        if(start < end){
            swap(s[start], s[end]);
        }

        return s == goal;
    }
};
