class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mid = nums.size() / 2;
        int start = 0; 
        int end = nums.size() - 1;
        int idx = partition(nums, start, end);
        while (idx != mid) {
            if (idx > mid) {
                end = idx - 1;
                idx = partition(nums, start, end);
            }
            else {
                start = idx + 1;
                idx = partition(nums, start, end);
            }
        }
        return nums[idx];
    }
    int partition(vector<int>& nums, int start, int end) {
        int index = randomInRange(start, end);
        swap(nums[index], nums[end]);
        int small = start - 1;
        for (index = start; index < end; index ++) {
            if (nums[index] < nums[end]) {
                swap(nums[++small], nums[index]);
            }
        }
        swap(nums[++small], nums[index]);
        return small;
    }
    int randomInRange(int start, int end) {
        srand(time(NULL));
        return start + rand() % (end - start + 1);
    }
};