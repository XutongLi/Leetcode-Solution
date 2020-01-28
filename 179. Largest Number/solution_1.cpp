class Solution {
private:
    static bool cmp(const int &a, const int &b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0)
            return "0";
        string res;
        for (auto n : nums)
            res += to_string(n);
        return res;
    }
};
//O(nlogn)