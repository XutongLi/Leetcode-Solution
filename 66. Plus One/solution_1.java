class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for (int i = len - 1; i >= 0; i --) {
            if (digits[i] != 9) {
                digits[i] ++;
                break;
            }
            else {
                digits[i] = 0;
            }
        }
        if (digits[0] == 0) {
            int result[] = new int[len + 1];
            result[0] = 1;
            return result;
        }
        return digits;
    }
}