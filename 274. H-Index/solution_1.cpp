class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        sort(citations.rbegin(), citations.rend());
        int n = citations.size();
        for (int i = 0; i < n; ++ i) {
            if (citations[i] < i + 1)
                return i;
        }
        return n;
    }
};
//O(nlogn)