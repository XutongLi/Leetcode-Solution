class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0, n = A.size();
        unordered_map<int, int> AB;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) { 
                ++ AB[A[i] + B[j]];
            }
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j)
                res += AB[-C[i] - D[j]];
        }
        return res;
    }
};
//O(n^2)