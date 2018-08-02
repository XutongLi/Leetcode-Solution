//recursive
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
        return reverseList(head, null);
    }

    public ListNode reverseList(ListNode current, ListNode prev) {
        if (current == null)    return prev;
        ListNode next = current.next;
        current.next = prev;
        return reverseList(next, current);
    }
}

