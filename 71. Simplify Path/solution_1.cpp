class Solution {
public:
    string simplifyPath(string path) {
        string res = "", tmp;
        stringstream ss(path);
        vector<string> vec;
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".")
                continue;
            if (tmp != "..")
                vec.push_back(tmp);
            else if (!vec.empty())  //tmp == ".."
                vec.pop_back();
        }
        for (auto str : vec)
            res += "/" + str;
        return res.empty() ? "/" : res;
    }
};
// ... 可以作为文件名存在