class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(256, 0);
        vector<bool> visited(256, false);
        for (auto c : s)
            ++ cnt[c];
        string res("");
        for (auto c : s) {
            -- cnt[c];
            if (visited[c])
                continue;
            while (!res.empty() && c < res.back() && cnt[res.back()] > 0) { //后续位置还有res.back时才可以删除
                visited[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            visited[c] = true;
        }
        return res;
    }
};
//time O(26n)   space O(256)
//stack solution(use res.pop_back to implement stack)