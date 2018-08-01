/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)   return head;
        ListNode fast = head.next;
        ListNode slow = head;
        while(fast != null) {
            if (fast.val == slow.val) {
                fast = fast.next;
                slow.next = slow.next.next;
            }
            else {
                fast = fast.next;
                slow = slow.next;
            }
        }
        return head;
    }
}