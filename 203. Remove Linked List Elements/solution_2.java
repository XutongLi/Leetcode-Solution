//98.47%
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
        ListNode forward = new ListNode(-1);
        forward.next = head;
        ListNode ptr = forward;
        while (ptr.next != null) {
            if (ptr.next.val == val) {
                ptr.next = ptr.next.next;
            }
            else {
                ptr = ptr.next;
            }
        }
        return forward.next;
    }
}