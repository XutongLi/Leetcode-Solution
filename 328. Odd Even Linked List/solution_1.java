//100%
//o(nodes)  o(1)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null)  
            return head;
        ListNode oddHead = head;
        ListNode evenHead = head.next;
        ListNode oddPtr = oddHead;
        ListNode evenPtr = evenHead;
        while (evenPtr != null && evenPtr.next != null) {
            oddPtr.next = oddPtr.next.next;
            evenPtr.next = evenPtr.next.next;
            oddPtr = oddPtr.next;
            evenPtr = evenPtr.next;
        }
        oddPtr.next = evenHead;
        return oddHead;
    }
}