class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
        string destination;
        for(int i = 0; i < paths.size(); i++){ 
                int flag = 0; 
                string& temp = paths[i][1];
                for(int j = 0; j < paths.size(); j++)
                    if(paths[j][0] == temp){
                        flag = 1;
                        break;
                    }
                if(flag == 0){
                    destination = temp;
                    break;
                }
        }
        return destination;
    }
};
