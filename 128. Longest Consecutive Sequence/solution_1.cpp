class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set st(nums.begin(), nums.end());
        int maxi = 0;
        for (int num : nums) {
            if (st.find(num - 1) != st.end()) 
                continue;
            int next = num + 1, cnt = 1;
            while (st.find(next) != st.end()) {
                ++ next;
                ++ cnt;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
//O(n)