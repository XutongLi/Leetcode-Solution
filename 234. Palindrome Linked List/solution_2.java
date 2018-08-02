//100%
//from discuss
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        if (head.val == head.next.val && head.next.next == null) {
            return true;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast.next != null) {
            if (fast.next.val == slow.val) {
                if(fast.next.next != null) {
                    return false;
                }
                fast.next = null;
                slow = slow.next;
                fast = slow.next;
                if (fast == null || slow.val == fast.val) {
                    return true;
                }
            }
            else {
                fast = fast.next;
            }
        }
        return false;
    }
}