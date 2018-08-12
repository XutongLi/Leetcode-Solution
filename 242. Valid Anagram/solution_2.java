//100%
//o(n)
//but cannot cover all ASCII characters
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.isEmpty() && t.isEmpty())
            return true;
        if (s.length() != t.length())
            return false;
        int[] alphabet = new int[26];
        for(char c : s.toCharArray()) 
            alphabet[c - 'a'] ++;     
        for(char c : t.toCharArray()) 
            alphabet[c - 'a'] --;
        for(int num : alphabet) {
            if(num != 0) {
                return false;
            }
        }
        return true;
    }
}