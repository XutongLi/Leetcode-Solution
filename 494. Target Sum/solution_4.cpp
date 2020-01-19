class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> cur, next, *p_cur = &cur, *p_next = &next;
        (*p_cur)[0] = 1;   
        for (int i = 0; i < nums.size(); ++ i) {
            for (auto &pair : *p_cur) {
                (*p_next)[pair.first + nums[i]] += pair.second;
                (*p_next)[pair.first - nums[i]] += pair.second;
            }
            swap(p_cur, p_next);
            (*p_next).clear();
        }
        return (*p_cur)[S];
    }
};
//优化空间复杂度为O(s)