class Solution {
private:
    void dfs(string &be, string &en, unordered_map<string, vector<string>> &mp, vector<string> &cur, vector<vector<string>> &res) {
        if (be == en) {
            res.push_back(cur);
            return;
        }
        for (string str : mp[be]) {
            cur.push_back(str);
            dfs(str, en, mp, cur, res);
            cur.pop_back();
        }
    }
    void getMinAndMap(string &be, string &en, const unordered_set<string> &words, unordered_map<string, vector<string>> &mp) { 
        unordered_set<string> visited;
        unordered_set<string> cur;
        unordered_set<string> pre;
        cur.insert(be);
        visited.insert(be);
        pre.insert(en);
        visited.insert(en);
        bool found = false, forward = true;
        while (!cur.empty() && !pre.empty()) {
            if (cur.size() > pre.size()) {
                swap(cur, pre);
                forward = !forward;
            }
            unordered_set<string> tmp;
            for (auto str : cur) {
                string raw = str;
                for (auto &c : str) {
                    char ctmp = c;
                    for (int i = 0; i < 26; ++ i) {
                        c = i + 'a';
                        if (pre.find(str) != pre.end()) {   //找到完整的相邻字符串路径
                            found = true;
                            if (forward) //区分顺序还是逆序
                                mp[raw].push_back(str);
                            else 
                                mp[str].push_back(raw);
                        }
                        if (visited.find(str) != visited.end() && tmp.find(str) == tmp.end())   //已访问过，但不是本层访问的
                            continue;
                        if (words.find(str) == words.end())
                            continue;
                        tmp.insert(str);
                        visited.insert(str);
                        if (forward) 
                            mp[raw].push_back(str);
                        else 
                            mp[str].push_back(raw);
                    }
                    c = ctmp;
                }
            }
            swap(cur, tmp);
            if (found)  break;  //已找到完整路径便不在循环，否则会得到不是最短长度的结果
        }
    }
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (words.find(end) == words.end())
            return res;
        unordered_map<string, vector<string>> mp;   //value为与key相邻的所有string
        getMinAndMap(begin, end, words, mp);
        vector<string> cur;
        cur.push_back(begin);
        dfs(begin, end, mp, cur, res);
        return res;
    }
};
//two end BFS寻找构建mp，卡最小长度，DFS保存路径