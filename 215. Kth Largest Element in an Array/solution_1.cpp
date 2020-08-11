class Solution {
private:
    int randInRange(int lo, int hi) {
        srand(time(0));
        return lo + rand() % (hi - lo + 1);
    }
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int partition(vector<int> &nums, int lo, int hi) {
        int index = randInRange(lo, hi);
        swap(nums[index], nums[hi]);
        int small = lo - 1;
        for (index = lo; index < hi; ++ index) {
            if (nums[index] > nums[hi]) {
                ++ small;
                swap(nums[index], nums[small]);
            }
                
        }
        ++ small;
        swap(nums[small], nums[hi]);
        return small;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int pivot = partition(nums, lo, hi);
            if (pivot + 1 < k) 
                lo = pivot + 1;
            else if (pivot + 1 > k)
                hi = pivot - 1;
            else
                return nums[pivot];
        }
        return nums[lo];
    }
};