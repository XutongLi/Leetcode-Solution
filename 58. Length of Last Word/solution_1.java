class Solution {
    public int lengthOfLastWord(String s) {
        int len = s.length();
        if (len == 0)   return 0;
        int count = 0;
        int lastcount = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == ' ') {
                if (count != 0) lastcount = count;
                count = 0;
            }
            else
                count ++;
        }
        return count == 0 ? lastcount : count;
    }
}