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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        if (lists.size() == 1)  return lists[0];
        int num = 1, cnt = lists.size();
        while (num < cnt) {
            for (int i = 0; i < cnt - num; i += num * 2) {
                lists[i] = merge2Lists(lists[i], lists[i + num]);
            }
            num *= 2;
        }
        return lists[0];
    }
    ListNode *merge2Lists(ListNode *l, ListNode *r) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            }
            else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        if (l)  cur->next = l;
        if (r)  cur->next = r;
        return head->next;
    }
};//o(nlogk) 