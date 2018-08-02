//100%
/**
 * get the length of the two linked list
 * get the difference of the two length
 * cut the larger one
 * compare
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)     return null;
        ListNode ptrA = headA;
        ListNode ptrB = headB;
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        int diff = Math.abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff -- > 0) {
                ptrA = ptrA.next;
            }
        }
        else {
            while (diff -- > 0) {
                ptrB = ptrB.next;
            }
        }
        while (ptrA != ptrB) {
            ptrA = ptrA.next;
            ptrB = ptrB.next;
        }
        return ptrA;
    }
    
    int getLen(ListNode head) {
        ListNode ptr = head;
        int count = 0;
        while (ptr != null) {
            count ++;
            ptr = ptr.next;
        }
        return count;
    }
}