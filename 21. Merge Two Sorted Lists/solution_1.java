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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null)     return l2;
        if (l2 == null)     return l1;
        ListNode forward = new ListNode(-1);
        ListNode ptr = forward;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                ptr.next = l1;
                l1 = l1.next;
            }
            else {
                ptr.next = l2;
                l2 = l2.next;
            }
            ptr = ptr.next;
        }
        if (l1 != null) {
            ptr.next = l1;
        }
        if (l2 != null) {
            ptr.next = l2;
        }
        return forward.next;
    }
}