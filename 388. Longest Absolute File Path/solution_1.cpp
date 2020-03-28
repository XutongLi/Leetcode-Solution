class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream is(input);
        string temp = "";
        unordered_map<int, int> mp; //key-深度(\t数量，如有1个\t的深度为2) val-此深度长度
        mp[0] = 0;
        int res = 0;
        while (getline(is, temp)) {
            auto iter = temp.find_last_of('\t');
            string str = (iter == string::npos) ? temp : temp.substr(iter + 1);
            int depth = temp.size() - str.size();
            if (str.find('.') != string::npos)
                res = max(res, mp[depth] + static_cast<int>(str.size()));
            else
                mp[depth + 1] = mp[depth] + str.size() + 1; //加一个'/''
        }
        return res;
    }
};