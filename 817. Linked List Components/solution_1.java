//95.82%
//o(nlogn)
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
        Arrays.sort(G);
        int count = 0;
        ListNode ptr = head;
        boolean series = false;
        while (ptr != null) {
            if (Arrays.binarySearch(G, ptr.val) >= 0) {
                if (!series) {
                    count ++;
                    series = true;
                }
            }
            else {
                series = false;
            }
            ptr= ptr.next;
        }
        return count;
    }
}