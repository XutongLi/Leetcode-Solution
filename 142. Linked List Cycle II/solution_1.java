//fast每次走两个结点，slow每次走一个结点，两者相遇时有环
//此时fast走了2x个结点，slow走了x个节点
//fast比slow夺走了r个环，环长度为n，所以2x=x+rn, x=rn
//设到环之前的结点数为y，那么slow在环中的长度为x-y，再走y步到达交汇处
//将fast指向头结点，也是走y个结点到达交汇处
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null)   return null;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast.next;
                    slow = slow.next;
                }
                return fast;
            }
        }
        return null;
    }
}