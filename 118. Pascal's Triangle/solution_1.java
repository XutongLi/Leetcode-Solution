class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> pre = new ArrayList<>();
        while (numRows -- > 0) {
            pre.add(0, 1);
            for (int i = 1; i < pre.size() - 1; i++) {
                pre.set(i, pre.get(i) + pre.get(i + 1));
            }
            res.add(new ArrayList(pre));
        }
        return res;
    }
}