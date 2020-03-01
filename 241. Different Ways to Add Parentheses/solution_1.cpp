class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int num = 0;
        string left = "";
        for (int i = 0; i < input.size(); ++ i) {
            if (isdigit(input[i])) {
                num = num * 10 + input[i] - '0';
            }
            else {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto l : left) {
                    for (auto r : right) {
                        if (input[i] == '+')
                            res.push_back(l + r);
                        else if (input[i] == '-')
                            res.push_back(l - r);
                        else if (input[i] == '*')
                            res.push_back(l * r);
                    }
                }
            }
        }
        if (res.empty())    //res为空时，此string中只有数字，无计算符号
            res.push_back(num);
        return res;
    }
};
//递归，分治法