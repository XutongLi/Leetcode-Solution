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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)  return nullptr;
        ListNode *fake = new ListNode(-1);
        fake->next = head;
        ListNode *ptr = head, *scan;
        while (ptr->next) {
            if (ptr->next->val >= ptr->val) {   //到此位置已有序
                ptr = ptr->next;
                continue;
            }
            scan = fake;
            while (scan->next->val <= ptr->next->val)
                scan = scan->next;
            //scan->next->val > ptr->next->val)
            //swap
            ListNode *tmp = scan->next;
            scan->next = ptr->next;
            ptr->next = ptr->next->next;
            scan->next->next = tmp;
        }
        return fake->next;
    }
};
//stable sort