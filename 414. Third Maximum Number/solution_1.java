class Solution {
    public int thirdMax(int[] nums) {
        ArrayList<Integer> array = new ArrayList<>();
        for (int num : nums) {
            if (!array.contains(num))
                array.add(num);
        }
        if (array.size() < 3)   return findMax(array, 1);
        return findMax(array, 3);
    }
    private int findMax(ArrayList<Integer> array, int k) {
        k--;
        int lo = 0, hi = array.size() - 1;
        while (lo < hi) {
            int j = partition(array, lo, hi);
            if (k < j)  hi = j - 1;
            else if (k > j) lo = j + 1;
            else    return array.get(k);
        }
        return array.get(k);
    }
    private int partition(ArrayList<Integer> array, int lo, int hi) {
        int pivot = array.get(lo);
        int i = lo, j = hi + 1;
        while (true) {
            while (array.get(++i) > pivot)
                if (i == hi)    break;
            while (array.get(--j) < pivot)
                if (j == lo)    break;
            if (i >= j) break;
            swap(array, i, j);
        }
        swap(array, lo, j);
        return j;
    }
    private void swap(ArrayList<Integer> array, int i, int j) {
        int tmp = array.get(i);
        array.set(i, array.get(j));
        array.set(j, tmp);
    }
}