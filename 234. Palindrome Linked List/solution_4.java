//reverse half of the list
//combine 876 middle of the linked list and 206 reverse linked list
//97.74%
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
        if (head == null || head.next == null)  return true;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        if (fast != null) {
            slow = slow.next;
        }
        ListNode newhead = reverse(slow);
        while (newhead != null) {
            if (newhead.val != head.val) {
                return false;
            }
            newhead = newhead.next;
            head = head.next;
        }
        return true;
    }
    
    ListNode reverse(ListNode head) {
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