class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        HashSet<Integer> set = new HashSet<>();
        int lenA = 0, lenB = 0;
        for (int a : A) {
            lenA += a;
        }
        for (int b : B) {
            lenB += b;
            set.add(b);
        }
        int dis = (lenA + lenB) / 2 - lenA;
        for (int a : A) {
            if (set.contains(a + dis))
                return new int[]{a, a + dis};
        }
        return new int[]{};
    }
}