//从右往左
class Solution {
    public int lengthOfLastWord(String s) {
        int len = s.length();
        if (len == 0)   return 0;
        int count = 0;
        boolean hasCount = false;
        for (int i = len - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                if (hasCount)   break;
            }
            else {
                hasCount = true;
                count ++;
            }
        }
        return count;
    }
}