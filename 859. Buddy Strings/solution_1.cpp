class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length())
            return false;
        if (A == B) {
            vector<int> mp(26, 0);
            for (auto ch : A) {
                ++ mp[ch - 'a'];
                if (mp[ch - 'a'] >= 2)
                    return true;
            }
            return false;
        }
        int idx1 = 0, idx2 = 0;
        bool first = true;
        for (int i = 0; i < A.size(); ++ i) {
            if (A[i] != B[i]) {
                if (first) {
                    idx1 = i;
                    first = false;
                }
                else {
                    idx2 = i;
                    break;
                }
            }
        }
        swap(A[idx1], A[idx2]);
        return A == B;
    }
};