class Solution {
private:
    vector<string> below20 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> below100 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string getNum(int num) {
        if (num >= 1000000000)
            return getNum(num / 1000000000) + " Billion" + getNum(num - 1000000000 * (num / 1000000000));
        if (num >= 1000000)
            return getNum(num / 1000000) + " Million" + getNum(num - 1000000 * (num / 1000000));
        if (num >= 1000)
            return getNum(num / 1000) + " Thousand" + getNum(num - 1000 * (num / 1000));
        if (num >= 100)
            return getNum(num / 100) + " Hundred" + getNum(num - 100 * (num / 100));
        if (num >= 20)
            return string(" ") + below100[num / 10 - 2] + getNum(num - 10 * (num / 10));
        if (num > 0)
            return string(" ") + below20[num];
        return "";
    }
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        return getNum(num).substr(1);
    }
};