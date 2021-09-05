class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; ++ i) {
            //res.push_back(1);
            if (mp.find(s[i]) != mp.end()) {
                int len = i - mp[s[i]] + 1;
                int sum = 1;
                while (!res.empty() && sum < len) {
                    sum += res.back();
                    res.pop_back();
                }
                res.push_back(sum);
            } 
            else {
                res.push_back(1);
                mp[s[i]] = i;
            }
        }
        return res;
    }
};