//42%
//O(n)
//two hashmaps
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null || nums1.length == 0 || nums2.length == 0)
            return new int[0];
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> inter = new HashMap<>();
        for (int num : nums1) {
            if (!map.containsKey(num))
                map.put(num, 1);
            else {
                int val = map.get(num);
                map.put(num, ++val);
            }
        }
        for (int num : nums2) {
            if (map.containsKey(num)) {
                int val = map.get(num);
                if (val > 0) {
                    map.put(num, --val);
                    if (!inter.containsKey(num))
                        inter.put(num, 1);
                    else {
                        int interval = inter.get(num);
                        inter.put(num, ++interval);
                    }
                }
            } 
        }
        int k = 0;
        for (Map.Entry<Integer, Integer> entry : inter.entrySet()) {
	        Integer key = entry.getKey();
			Integer value = entry.getValue();
			while (value-- > 0)
                nums1[k++] = key;
        }   
        return Arrays.copyOf(nums1, k);
    }
}