class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> maxIdxPerWord(26);
        for (int i = 0; i < S.size(); ++ i) 
            maxIdxPerWord[S[i] - 'a'] = i;
        int maxIdx = -1, lastIdx = -1;
        for (int i = 0; i < S.size(); ++ i) {
            // maxIdx保存当前group中所有word的最大index
            maxIdx = max(maxIdx, maxIdxPerWord[S[i] - 'a']);
            if (maxIdx == i) {  // 当前idx为当前group最大idx时，表明一个group结束
                res.push_back(i - lastIdx);
                lastIdx = i;
            }
        }
        return res;
    }
};
// greedy