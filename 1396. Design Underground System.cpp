class UndergroundSystem {
public:
    map<int,pair<string,int>> in;

    map<pair<string,string>,pair<int,int>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        avg[{stationName,in[id].first}]={avg[{stationName,in[id].first}].first+t-in[id].second,avg[{stationName,in[id].first}].second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return double(double(avg[{endStation,startStation}].first)/double(avg[{endStation,startStation}].second));
    }
};
