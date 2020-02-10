class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        int res = 0, cur_end = 0, cur_farthest = 0;
        for (int i = 0; i < n - 1; ++ i) {
            cur_farthest = max(cur_farthest, i + nums[i]);
            if (i == cur_end) {
                ++ res;
                cur_end = cur_farthest;
            }
        }
        return res;
    }
};
//greedy time O(n) space O(1)
// Let's say the range of the current jump is [cur_begin, cur_end], cur_farthest is the farthest point that all points in [cur_begin, cur_end] can reach. Once the current point reaches cur_end, then trigger another jump, and set the new cur_end with cur_farthest, then keep the above steps
//this is also BFS
//This is an implicit bfs solution. i == cur_end means you visited all the items on the current level. Incrementing res++ is like incrementing the level you are on. And cur_end = cur_farthest is like getting the queue size (level size) for the next level you are traversing.