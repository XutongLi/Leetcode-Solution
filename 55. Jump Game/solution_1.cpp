class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastpos = n - 1;
        for (int i = n - 1; i >= 0; -- i) {
            if (nums[i] + i >= lastpos)
                lastpos = i;
        }
        return lastpos == 0;
    }
};//greedy