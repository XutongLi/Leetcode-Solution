class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt = 0, l = -1, r = -1;
        for (int i = 0; i < A.size(); ++ i) {
            if (A[i] > R)   l = i;
            if (A[i] >= L)  r = i;
            cnt += r - l;
        }
        return cnt;
    }
};