//Binary Search
//O(nlogn)
/**
 * 10 9 2 5 3 7 6 10 15 18 101 18
 * dp: 10               res = 0
 *     9                      0
 *     2                      0
 *     2 5                    1
 *     2 3                    1
 *     2 3 7                  2
 *     2 3 6                  2
 *     2 3 6 10               3
 *     2 3 6 10 15            4
 *     2 3 6 10 15 18         5
 *     2 3 6 10 15 18 101     6
 *     2 3 6 10 15 18 101     6
 * return res + 1 = 7
 */
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int res = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < dp[0])
                dp[0] = nums[i];
            else if (nums[i] > dp[res])
                dp[++res] = nums[i];
            else
                dp[binarySearch(res, dp, nums[i])] = nums[i];
        }
        return res + 1;
    }
    private int binarySearch(int hi, int[] dp, int target) {
        int lo = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (target < dp[mid])
                hi = mid - 1;
            else if (target > dp[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }
}