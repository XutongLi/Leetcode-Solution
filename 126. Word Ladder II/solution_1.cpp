class Solution {
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (words.find(end) == words.end())
            return res;
        
        multimap<string, vector<string>> mp;     //mp的value为到key的相邻字符串组成的vector
        unordered_set<string> cur;
        unordered_set<string> pre;
        cur.insert(begin);
        pre.insert(end);
        mp.insert(make_pair(begin, vector<string>{begin}));
        mp.insert(make_pair(end, vector<string>{end}));
        //int res = 2;
        bool found = false;
        while (!cur.empty() && !pre.empty()) {
            if (cur.size() > pre.size())
                swap(cur, pre);
            unordered_set<string> tmp;
            for (auto str : cur) {
                string raw = str;
                for (auto &c : str) {
                    char ctmp = c;
                    for (int i = 0; i < 26; ++ i) {
                        c = i + 'a';
                        if (pre.find(str) != pre.end()) {   //找到从begin到end相邻字符串路径
                            //return res;
                            found = true;
                            auto it = mp.find(str);
                            auto cnt = mp.count(str);
                            for (int i = 0; i < cnt; ++ i) {
                                auto vec = it->second;
                                auto it_raw = mp.find(raw);
                                auto cnt_raw = mp.count(raw);
                                for (int j = 0; j < cnt_raw; ++ j) {
                                    auto raw_vec = it_raw->second;
                                    if (vec.back() == begin) {  //已有d-e，找d的相邻c，发现已有c-b-a
                                        vector<string> cur(vec.rbegin(), vec.rend());
                                        cur.insert(cur.end(), raw_vec.begin(), raw_vec.end());
                                        res.push_back(cur);
                                    }
                                    else { //mp[str].back() == end  已有b-a,找b的相邻c，发现已有c-d-e
                                        vector<string> cur(raw_vec.rbegin(), raw_vec.rend());
                                        cur.insert(cur.end(), vec.begin(), vec.end());
                                        res.push_back(cur);
                                    }
                                    ++ it_raw;
                                }
                                ++ it;
                            }
                        }
                        if (mp.find(str) != mp.end() && tmp.find(str) == tmp.end())   //此str已访问过，但是不是在本层次中访问的
                            continue;
                        if (words.find(str) == words.end()) //words中没有该str
                            continue;
                        tmp.insert(str);
                        //维护mp
                        auto it = mp.find(raw);
                        auto cnt = mp.count(raw);
                        for (int i = 0; i < cnt; ++ i) {
                            vector<string> second = it->second;
                            vector<string> vec = {str};
                            vec.insert(vec.end(), second.begin(), second.end());
                            mp.insert(make_pair(str, vec));
                            ++ it;
                        }
                    }
                    c = ctmp;
                }
            }
            //++ res;
            swap(cur, tmp);
            if (found)  break;      //找到路径即停止循环，否则后序找到的路径都不是最短的
        }
        return res;
    }
};
//two end BFS + multimap