class SnapshotArray {
    vector<vector<pair<int, int>>> snaps;
    int curSnap;
public:
    SnapshotArray(const int& length) {
        snaps.resize(length, {{-1, 0}});
        curSnap = 0;
    }
    
    void set(const int& index, const int& val) { 
        if (snaps[index].back().first < curSnap)
            snaps[index].push_back({curSnap, val});
        else
            snaps[index].back().second = val;
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(const int& index, const int& snap_id) {
        return (upper_bound(snaps[index].begin(), snaps[index].end(), make_pair(snap_id, INT_MAX)) - 1)->second;
    }
};
