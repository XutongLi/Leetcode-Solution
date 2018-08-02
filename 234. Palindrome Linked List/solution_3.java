//use stack only
//7.58%
//from discuss
//not a great method
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
        Stack<Integer> stack = new Stack<Integer>();
        ListNode ptr = head;
        while (ptr != null) {
            stack.push(ptr.val);
            ptr = ptr.next;
        }
        while (head != null) {
            if (head.val != stack.pop()) {
                return false;
            }
            head = head.next;
        }
        return true;
    }
}