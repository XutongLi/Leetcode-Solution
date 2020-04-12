class Solution {
private:
    //用于获得在[s,e]范围内，当前player和另一个player的分数差
    int getmore(const vector<int> &nums, int s, int e, vector<vector<int>> & mem) {
        if (s == e)
            return nums[e];
        if (mem[s][e] != INT_MAX)
            return mem[s][e];
        //例如当前为player1，取了nums[s]，则nums[s] - getmore(nums, s + 1, e, mem)是他比player2多出的分数
        int pick_s = nums[s] - getmore(nums, s + 1, e, mem);    
        int pick_e = nums[e] - getmore(nums, s, e - 1, mem);
        mem[s][e] = max(pick_s, pick_e);
        return mem[s][e];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, INT_MAX));
        //最开始是player1先取，所以当他和player2的分数差大于等于0，在player1获胜
        return getmore(nums, 0, n - 1, mem) >= 0;   
    }
};
//dp (minmax question)
//time O(n^2)  space O(n^2)
//https://leetcode.com/articles/predict-the-winner/