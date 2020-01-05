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
        if (!head)
            return nullptr;
        return mergeSort(head);
    }
    ListNode *mergeSort(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *fast = pre, *slow = pre;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head = mergeSort(head);
        head2 = mergeSort(head2);
        return merge(head, head2);
    }
    ListNode *merge(ListNode *head1, ListNode *head2) {
        if (!head1)     return head2;
        if (!head2)     return head1;
        ListNode *pre = new ListNode(-1);
        ListNode *ptr = pre; 
        while (head1 && head2) {
            if (head1->val < head2->val) {
                ptr->next = head1;
                head1 = head1->next;
            }
            else {
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }
        if (head1)
            ptr->next = head1;
        if (head2)
            ptr->next = head2;
        return pre->next;
    }
    
};