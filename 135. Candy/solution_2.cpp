class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0)
            return 0;
        vector<int> vec(n, 1);
        for (int i = 1; i < n; ++ i) {
            if (ratings[i] > ratings[i - 1] && vec[i] <= vec[i - 1])
                vec[i] = vec[i - 1] + 1;
        }
        int res = vec[n - 1];
        for (int i = n - 2; i >= 0; -- i) {
            if (ratings[i] > ratings[i + 1] && vec[i] <= vec[i + 1])
                vec[i] = vec[i + 1] + 1;
            res += vec[i];
        }
        return res;
    }
};
//greedy time
//优化solution_1
//O(2n) space O(n)