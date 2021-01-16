class Solution {
private:
	int search(vector<int> &nums, int target, int l, int r) {
		if (l > r)		return l;
		int m = (r - l) / 2 + l;
		if (nums[m] == target)	
			return m;
		else if (nums[m] > target)
			return search(nums, target, l, m - 1);
		else
			return search(nums, target, m + 1, r);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};
