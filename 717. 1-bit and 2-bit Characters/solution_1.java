class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        if (bits.length == 1) {
            return true;
        }
        if (bits[bits.length - 2] == 0) {
            return true;
        }
        int count = 0;
        for (int i = bits.length - 2; i >= 0 && bits[i] != 0; i--) {
            count ++;
        }
        if (count % 2 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}