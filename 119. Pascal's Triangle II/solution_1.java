class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        if (rowIndex == 0)  return list;
        list.add(1);
        for (int i = 1; i < rowIndex; i++) {
            for (int j = 0; j < list.size() - 1; j++) {
                list.set(j, list.get(j) + list.get(j + 1));
            }
            list.add(0, 1);
        }
        return list;
    }
}