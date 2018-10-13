class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        if (numRows == 0)   return res;
        res.add(new ArrayList<Integer>());
        res.get(0).add(1);
        for (int i = 1; i < numRows; i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    list.add(1);
                else
                    list.add(res.get(i - 1).get(j) + res.get(i - 1).get(j - 1));
            }
            res.add(list);
        }
        return res;
    }
}