class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
            return 0;
        
        unordered_set<string> next;
        unordered_set<string> prev;
        next.insert(beginWord);
        words.erase(beginWord);
        prev.insert(endWord);
        words.erase(endWord);
        
        int res = 2;
        while (!next.empty() && !prev.empty()) {
            if (next.size() > prev.size())
                swap(next, prev);   //每次对words少的set进行BFS
            unordered_set<string> tmp;
            for (auto str : next) {
                for (auto &c : str) {
                    char ctmp = c;
                    for (int i = 0; i < 26; ++ i) {
                        c = i + 'a';
                        if (prev.find(str) != prev.end())
                            return res;
                        if (words.find(str) != words.end()) {
                            tmp.insert(str);
                            words.erase(str);
                        }
                    }
                    c = ctmp;
                }
            }
            ++ res;
            swap(next, tmp);
        }
        return 0;
    }
};
//two end BFS
//从两头进行BFS，每次对word数量较少的一头进行BFS，直到两头相连（即两头存在只差一个alpha的word）