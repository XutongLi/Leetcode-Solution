class Solution {
public:
    int countSegments(string s) {
        stringstream str(s);
        int res = 0;
        string tmp;
        while (str >> tmp)
            ++ res;
        return res;
    }
};