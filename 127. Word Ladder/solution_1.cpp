class Solution {
private:
    // int dis(const string &a, const string &b) {
    //     int di = 0;
    //     for (int i = 0; i < a.size(); ++ i) {
    //         if (a[i] != b[i])
    //             ++ di;
    //     }
    //     return di;
    // }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while (!q.empty()) {
            ++ res;
            int size = q.size();
            for (int i = 0; i < size; ++ i) {
                if (q.front() == endWord)
                    return res;
                string str = q.front();
                q.pop();
                words.erase(str);
                // for (auto w : words) {
                //     if (dis(str, w) == 1) 
                //         q.push(w);
                // }
                for (auto &c : str) {
                    char tmp = c;
                    for (int a = 0; a < 26; ++ a) {
                        c = a + 'a';
                        if (words.find(str) != words.end()) {
                            q.push(str);
                        }
                    }
                    c = tmp;
                }
            }
        }
        return 0;
    }
};
//BFS
//O(N*M)