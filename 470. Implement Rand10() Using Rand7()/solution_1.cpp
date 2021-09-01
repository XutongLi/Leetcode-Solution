// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int rand49 = INT_MAX;
        while (rand49 >= 40) {
            rand49 = (rand7() - 1) * 7 + rand7() - 1;
        }
        return rand49 / 4 + 1;
    }
};

//很简单，你先想用rand10产生rand7，大于7的不要直接就好了；
//然后想rand25产生rand7，大于21的不要，剩下的数除3或模7+1；
//然后考虑rand7到rand10，就知道关键在于产生等概率分布的比10大的1～N就好了，
//rand7一次肯定不会产生比10大的数，那就取两次呗，
//为了保证概率密度相等，就用进制的思想（一一映射），一个rand7作为七进制第二位，一个rand7作为7进制第一位，
//得到的数刚好就是均匀分布的 0～48（两位七进制最大就48），然后去掉39以上，剩下的除4或模10加1就好了