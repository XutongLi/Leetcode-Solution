//9.67%
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null)   return null;
        ListNode ptr = head;
        while (ptr.next != null) {
            if (head.val == val) {
                head = head.next;
                ptr = head;
            }
            else if (ptr.next.val == val) {
                ptr.next = ptr.next.next;
            }
            else {
                ptr = ptr.next;
            }
        }
        if (ptr.val == val) {
            return null;
        }
        return head;
    }
}