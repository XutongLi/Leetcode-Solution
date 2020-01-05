/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *lh = new ListNode(-1);
        ListNode *mh = new ListNode(-1);
        ListNode *rh = new ListNode(-1);
        ListNode *lp = lh, *mp = mh, *rp = rh;
        int val = head->val;
        while (head) {
            if (head->val < val) {
                lp->next = head;
                lp = lp->next;
            }
            else if (head->val == val) {
                mp->next = head;
                mp = mp->next;
            }
            else {
                rp->next = head;
                rp = rp->next;
            }
            head = head->next;
        }
        lp->next = nullptr;
        rp->next = nullptr;
        lh->next = sortList(lh->next);
        rh->next = sortList(rh->next);
        
        lp = lh;
        while (lp->next)
            lp = lp->next;
        lp->next = mh->next;
        mp->next = rh->next;
        return lh->next;
    }
};
//三路快排
//取第一个为pivot，比pivot小的一个链表，比pivot大的一个链表，相等的一个链表
//大小链表分别排序，再按照小、相等、大连接起来