class Solution {
public:
    int calculate(string s) {
        deque<string> nums;
        int l, r;
        bool start = false;
        for (int i = 0; i < s.size(); ++ i) {
            if (isdigit(s[i])) {
                if (!start) {
                    start = true;
                    l = i;
                }
                r = i;
                if (i == static_cast<int>(s.size()) - 1)
                    nums.push_back(s.substr(l, r - l + 1));
            }
            else {
                if (start) {
                    start = false;
                    nums.push_back(s.substr(l, r - l + 1));
                }
                if (s[i] == ' ')
                    continue;
                nums.push_back(string(1, s[i]));
            }
        }
        
        deque<string> p;
        //消去* /
        while (!nums.empty()) {
            string c = nums.front();
            nums.pop_front();
            if (c == "*") {
                int a = stoi(p.back());
                p.pop_back();
                int b = stoi(nums.front());
                nums.pop_front();
                p.push_back(to_string(a * b));
            }
            else if (c == "/") {
                int a = stoi(p.back());
                p.pop_back();
                int b = stoi(nums.front());
                nums.pop_front();
                p.push_back(to_string(a / b));
            }
            else
                p.push_back(c);
        }
        //计算+ -
        int res = stoi(p.front());
        p.pop_front();
        while (!p.empty()) {
            string c = p.front();
            p.pop_front();
            if (c == "+") {
                int b = stoi(p.front());
                p.pop_front();
                res = res + b;
            }
            else if (c == "-") {
                int b = stoi(p.front());
                p.pop_front();
                res = res - b;
            }
        }
        return res;
    }
};
//乘法除法优先级相同