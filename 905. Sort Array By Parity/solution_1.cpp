class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = -1, j = A.size();
        while (1) {
            while (A[++i] % 2 == 0)
                if (i == A.size() - 1)
                    break;
            while (A[--j] % 2 == 1)
                if (j == 0)
                    break;
            if (i >= j)
                return A;
            swap(A[i], A[j]);
        }
    }
};