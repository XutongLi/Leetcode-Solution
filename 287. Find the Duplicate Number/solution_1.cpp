class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int fast = nums[nums[0]], slow = nums[0];
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
//refer to Linked List Cycle II.