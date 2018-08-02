//100%
//from discuss
//guile ORZ 
/**
 * Actually we don't care about the "value" of difference,
 * we just want to make sure two pointers reach the intersection node at the same time.
 * We can use two iterations to do that. In the first iteration, 
 * we will reset the pointer of one linkedlist to the head of another linkedlist 
 * after it reaches the tail node. In the second iteration, 
 * we will move two pointers until they points to the same node. 
 * Our operations in first iteration will help us counteract the difference. 
 * So if two linkedlist intersects, the meeting point in second iteration must be the intersection point. 
 * If the two linked lists have no intersection at all, 
 * then the meeting pointer in second iteration must be the tail node of both lists, which is null
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
        ListNode ptr1 = headA;
        ListNode ptr2 = headB;
        while (ptr1 != ptr2) {
            ptr1 = ptr1 == null ? headB : ptr1.next;
            ptr2 = ptr2 == null ? headA : ptr2.next;
        }
        return ptr1;
    }
}