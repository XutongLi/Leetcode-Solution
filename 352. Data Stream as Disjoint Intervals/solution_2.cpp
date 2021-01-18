class SummaryRanges {
private:
    map<int, pair<int, int>> mp;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {  // O(logN)
        if (mp.find(val) != mp.end())
            return;
        
        auto hi = mp.lower_bound(val);
        auto lo = (hi == mp.begin()) ? mp.end() : prev(hi);
        
        if (lo != mp.end() && hi != mp.end() && lo->second.second == val - 1 && hi->second.first == val + 1) {  // [2,2] [4,4] insert 3
            lo->second.second = hi->second.second;
            mp.erase(hi);
        }
        else if (lo != mp.end() && lo->second.second >= val - 1)    
            // [2,4] [7,7] insert 5 or insert 3
            lo->second.second = max(val, lo->second.second);
        else if (hi != mp.end() && hi->second.first == val + 1) {
            // [2,4] [7,7] insert 6
            mp[val] = {val, hi->second.second};
            mp.erase(hi);
        }
        else {  // [2,4] [8,8] insert 6
            mp[val] = {val, val};
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto p : mp)
            res.push_back(vector<int>{p.second.first, p.second.second});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */