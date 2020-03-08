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
    ListNode *reverse(ListNode *node) {
        ListNode *fast = node, *slow = nullptr;
        while (fast) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        return slow;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = len(l1), len2 = len(l2);
        if (len1 < len2) {    //令l1是更长的
            swap(l1, l2);
            swap(len1, len2);
        }
        ListNode *head = new ListNode(0);  
        ListNode *pre = head;
        for (int i = 0; i < len1 - len2; ++ i) {
            ListNode *node = new ListNode(l1->val);
            l1 = l1->next;
            node->next = pre;
            pre = node;
        }
        for (int i = 0; i < len2; ++ i) {
            ListNode *node = new ListNode(l1->val + l2->val);
            node->next = pre;
            pre = node;
            while (node->val >= 10) {
                node->val -= 10;
                node = node->next;
                node->val += 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *res = reverse(pre);
        if (res->val == 0)
            return res->next;
        else
            return res;
    }
};
//time O(n)  space O(1)
//倒着构建链表，最后翻转回来
//reverse solution