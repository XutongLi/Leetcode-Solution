class Solution {
private:
    void dfs(const vector<int> &arr, int idx, int target, int ignore, vector<vector<int>> &res, vector<int> &cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (idx == arr.size())
            return;
        if (arr[idx] <= target) {   //当该数字比target大后，后面的更大数字也无需再遍历
            if (arr[idx] != ignore) {
                cur.push_back(arr[idx]);
                dfs(arr, idx + 1, target - arr[idx], INT_MIN, res, cur);
                cur.pop_back();   
            }
            dfs(arr, idx + 1, target, arr[idx], res, cur);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, 0, target, INT_MIN, res, cur);
        return res;
    }
};
//backtracking
//ignore表示上一位忽略的数（上一位若无忽略，为INT_MIN），若此位数与上一位忽略数一样，则次数也忽略
//如1 1 2 5 6 7 10  target = 8
//第二个1，若ignore为1，表示第一个1被忽略，则第二个1也应该被忽略，否则与第一个1未忽略的情况重复