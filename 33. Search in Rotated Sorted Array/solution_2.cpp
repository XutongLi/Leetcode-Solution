class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] <= nums[r]) {     //612345
                if (target > nums[mid] && target <= nums[r])   
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else {  //567123
                if (target < nums[mid] && target >= nums[l])    
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return -1;
    }
};