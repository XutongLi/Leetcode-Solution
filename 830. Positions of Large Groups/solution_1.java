class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> res = new ArrayList<>();
        int start = 0, end = 0;
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) == S.charAt(i - 1)) {
                end = i;
            }
            else {
                if (end - start + 1 >= 3) {
                    List<Integer> list = new ArrayList<>();
                    list.add(start);
                    list.add(end);
                    res.add(list);
                }
                start = i;   
            }
        }
        if (end - start + 1 >= 3) {
            List<Integer> list = new ArrayList<>();
            list.add(start);
            list.add(end);
            res.add(list);
        }
        return res;
    }
}