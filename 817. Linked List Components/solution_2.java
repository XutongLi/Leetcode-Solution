//89.85%
//o(n)	o(n)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        Set<Integer> set = new HashSet<>();
        for(int n : G) {
            set.add(n);
        }
        int count = 0;
        ListNode ptr = head;
        boolean series = false;
        while (ptr != null) {
            if (set.contains(ptr.val)) {
                if (!series) {
                    count ++;
                    series = true;
                }
            }
            else {
                series = false;
            }
            ptr = ptr.next;
        }
        return count;
    }
}