class FoodRatings {
public:
    map< string  , map< int , set< string> , greater<int> >> mp; 
    unordered_map< string , pair< int , string> > mp1;  
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>&  ratings) {
        for(int i = 0; i < foods.size(); i++){
            mp1[foods[i]] = { ratings[i] , cuisines[i]};
        }
        
        for(int i = 0; i < cuisines.size(); i++){
            mp[cuisines[i]][ ratings[i]].insert(foods[i]);
        }
    } 
    void changeRating(string food, int newRating) {
        string cu = mp1[food].second;
        int currRating = mp1[food].first;
        auto it = mp[cu][currRating].find(food);
        mp[cu][currRating].erase(it);
        if(mp[cu][currRating].size() == 0){
            mp[cu].erase(currRating);
        }
         
        mp[cu][newRating].insert(food); 
        mp1[food] = {newRating , cu};
    }
    string highestRated(string cuisine) {
        if(mp.find(cuisine)!=mp.end()){
            auto it = mp[cuisine].begin();
            string ans = *it -> second.begin();
            return ans;
        }
        return "";
    }
};
