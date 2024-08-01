class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            int f = details[i][11]-'0', s = details[i][12]-'0';
            int age = f*10+s;
            if(age>60){
                count++;
            }
        }
        return count;
    }
};
