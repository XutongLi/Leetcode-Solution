class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = 0, beg = 0;
        vector<string> res;
        for (int i = 0; i < words.size(); ++ i) {
            if (len + words[i].size() > maxWidth - (i - beg)) { //当加上下一word长度超过了maxwidth减去所需空格长度，计算本行sub
                //blank为间隔个数，space为空格总个数
                int blank = i - beg - 1, num = blank, space = maxWidth - len;
                string sub = "";
                for (int j = 0; j < num; ++ j) {
                    sub += words[beg ++];
                    sub += string((space + blank - 1) / blank, ' ');    //放置空格，尽量均匀，不均匀时前面得比后面的长
                    space -= (space + blank - 1) / blank;
                    -- blank;
                }
                sub += words[beg];
                if (sub.size() < maxWidth)
                    sub += string(maxWidth - sub.size(), ' ');  //此行只有一个单词时，直接在单词后加入空格
                res.push_back(sub);
                len = words[i].size();
                beg = i;
            }
            else
                len += words[i].size();
        }
        //最后一行，要从左到右
        string sub = "";
        for (int i = beg; i < words.size(); ++ i) {
            if (i > beg)    
                sub += " ";
            sub += words[i];
        }
        sub += string(maxWidth - sub.size(), ' ');
        res.push_back(sub);
        return res;
    }
};
//time O(n)  space O(1)