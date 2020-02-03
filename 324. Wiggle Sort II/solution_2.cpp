class Solution {
private:
    //坐标变换
    //由大到小排序后，坐标 012345 ->135024  01234->13024
    int idx(int i, int n) {
        return (2 * i + 1) % ((n % 2 == 1) ? n : n + 1);
    }
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty())
            return;
        int n = nums.size();
        auto mid_iter = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_iter, nums.end());   //找到中位数并放在中间位置
        int mid = *mid_iter;    //中位数
        int lo = 0, cur = 0, hi = n - 1;
        while (cur <= hi) {
            if (nums[idx(cur, n)] > mid) {  //把比mid大的放在前面
                swap(nums[idx(cur, n)], nums[idx(lo, n)]);
                ++ cur;
                ++ lo;
            }
            else if (nums[idx(cur, n)] < mid) {
                swap(nums[idx(cur, n)], nums[idx(hi, n)]);
                -- hi;
            }
            else
                ++ cur;
        }
    }
};
//3 way partition + vitual index（通过index对应关系）
//O(n)
//3 way partition:http://brianleelxt.top/2018/08/10/quickSort/
//too dificult