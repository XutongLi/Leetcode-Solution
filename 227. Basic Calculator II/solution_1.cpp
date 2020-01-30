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
        
        deque<string> q, p;
        //消去*
        while (!nums.empty()) {
            string c = nums.front();
            nums.pop_front();
            if (c == "*") {
                int a = stoi(q.back());
                q.pop_back();
                int b = stoi(nums.front());
                nums.pop_front();
                q.push_back(to_string(a * b));
            }
            else
                q.push_back(c);
        }
        //消去/
        while (!q.empty()) {
            string c = q.front();
            q.pop_front();
            if (c == "/") {
                int a = stoi(p.back());
                p.pop_back();
                int b = stoi(q.front());
                q.pop_front();
                p.push_back(to_string(a / b));
            }
            else {
                p.push_back(c);
            }
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
//乘法优先级比除法高的情况下 (Wrong Answer)