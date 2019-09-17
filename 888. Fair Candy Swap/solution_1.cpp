class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        vector<int> res;
        int lenA = 0, lenB = 0;
        for (int i = 0; i < A.size(); i ++)
            lenA += A[i];
        for (int i = 0; i < B.size(); i ++) {
            lenB += B[i];
            s.insert(B[i]);
        }
        int diff = (lenA + lenB) / 2 - lenA;
        for (int a : A) {
            if (s.find(a + diff) != s.end()) {
                res.push_back(a);
                res.push_back(a + diff);
                return res;
            }
        }
        return res;
    }
};