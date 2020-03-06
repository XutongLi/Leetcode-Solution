class SummaryRanges {
private:
    list<vector<int>> lst;
    unordered_map<int, list<vector<int>>::iterator> mp;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {  //O(n)
        if (mp.find(val) == mp.end()) {
            auto ptr = lst.begin(), pre = ptr;
            while (ptr != lst.end() && (*ptr)[0] < val) {   //找到第一个大于val的位置
                pre = ptr;
                ++ ptr;
            }
            if (mp.find(val - 1) != mp.end() && mp.find(val + 1) != mp.end()) { //小于val部分，val，大于val部分merge到一起
                (*ptr)[0] = (*pre)[0];
                mp[val] = ptr;
                for (int i = (*pre)[0]; i <= (*pre)[1]; ++ i)   //O(n)
                    mp[i] = ptr;
                lst.erase(pre);
            }
            else if (mp.find(val - 1) != mp.end()) {    //与小于val部分merge
                (*pre)[1] = val;
                mp[val] = pre;
            }
            else if (mp.find(val + 1) != mp.end()) {    //与大于val部分merge
                (*ptr)[0] = val;
                mp[val] = ptr;
            }
            else {
                auto cur = lst.insert(ptr, vector<int>{val, val});  //不需要merge，直接插入
                mp[val] = cur;
            }
        }
    }
    
    vector<vector<int>> getIntervals() {    //O(n)
        return vector<vector<int>>(lst.begin(), lst.end());
    }
};
//list + hash
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */