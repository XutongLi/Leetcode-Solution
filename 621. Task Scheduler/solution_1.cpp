class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty())  return 0;
        unordered_map<char, int> mp;
        int maxi = 0;
        for (auto task : tasks) {
            ++ mp[task];
            maxi = max(maxi, mp[task]);
        }
        int res = (maxi - 1) * (n + 1);
        for (auto pair : mp) {
            if (pair.second == maxi)
                ++ res;
        }
        return max(res, static_cast<int>(tasks.size()));
    }
};
//https://leetcode.com/problems/task-scheduler/discuss/104504/C%2B%2B-8lines-O(n)
//AAAABBBBCCCDDEE n = 2
//A--A--A--
//AB-AB-AB-AB
//ABCABCABCAB
//剩下DE在在保持n距离的情况下随便放，此时长度为tasks.size()

//AAAABBC n = 2
//A--A--A--
//A--A--A--A
//ABCAB-A--A
//此时长度为res