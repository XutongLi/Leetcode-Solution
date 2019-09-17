class Solution {
public:
    int thirdMax(vector<int>& num) {
        vector<int> nums;
        for (int n : num) {
            vector<int>::iterator iter = find(nums.begin(), nums.end(), n);
            if (iter == nums.end())
                nums.push_back(n);
        }
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        int lo = 0;
        int hi = nums.size() - 1;
        int idx = partition(nums, lo, hi);
        while (idx != 2) {
            if (idx > 2) {
                hi = idx - 1;   
                idx = partition(nums, lo, hi);
            }
            else {
                lo = idx + 1;
                idx = partition(nums, lo, hi);
            }
        }
        return nums[idx];
    }
    int partition(vector<int>& nums, int start, int end) {
        int idx = randomInRange(start, end);
        swap(nums[idx], nums[end]);
        int small = start - 1;
        for (idx = start; idx < end; idx ++) {
            if (nums[idx] > nums[end]) {
                ++ small;
                swap(nums[idx], nums[small]);
            }
        }
        ++ small;
        swap(nums[small], nums[end]);
        return small;
    }
    int randomInRange(int start, int end) {
        srand(time(NULL));
        return start + rand() % (end - start + 1);
    }
};