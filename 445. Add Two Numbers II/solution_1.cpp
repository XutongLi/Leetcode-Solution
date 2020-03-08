/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int len(ListNode *l) {
        int cnt = 0;
        while (l) {
            l = l->next;
            ++ cnt;
        }
        return cnt;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = len(l1), len2 = len(l2);
        if (len1 < len2) {    //令l1是更长的
            swap(l1, l2);
            swap(len1, len2);
        }
        ListNode *head = new ListNode(0);   //既做头结点，也做潜在的进位
        ListNode *not9 = head, *ptr = head;  //not9为结果链表当前节点前最近的不为9的节点
        for (int i = 0; i < len1 - len2; ++ i) {
            ptr->next = new ListNode(l1->val);
            l1 = l1->next;
            ptr = ptr->next;
            if (ptr->val < 9)
                not9 = ptr;
        }
        for (int i = 0; i < len2; ++ i) {
            int sum = l1->val + l2->val;
            if (sum <= 9) 
                ptr->next = new ListNode(sum);
            else {
                ptr->next = new ListNode(sum - 10);
                ++ not9->val;
                while (not9 != ptr) {
                    not9 = not9->next;
                    not9->val = 0;
                }
            }
            l1 = l1->next;
            l2 = l2->next;
            ptr = ptr->next;
            if (ptr->val < 9)
                not9 = ptr;
        }
        if (head->val == 1) 
            return head;
        else
            return head->next;
    }
};
//time O(n)  space O(1)
//without reverse
//如：199998,8之前的not9为1