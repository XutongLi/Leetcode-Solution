//100%
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode fast = head;
        ListNode slow = null;
        while (fast != null) {
            ListNode temp = fast.next;
            fast.next = slow;
            slow = fast;
            fast = temp;
        }
        return slow;
    }
}