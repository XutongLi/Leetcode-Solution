//from discuss
//i think it is not a good method
//it destroys the original list
//14.95%
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
    public boolean hasCycle(ListNode head) {
    	ListNode p = head, pre = head;
    	while(p != null){
    		if (p.next == head)     return true;
    		p = p.next;
    		pre.next = head;
    		pre = p;
    	}
        return false;
    }
}