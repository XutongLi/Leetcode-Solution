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
    struct cmp {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        if (lists.size() == 1)  return lists[0];
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto ptr : lists) {
            if (ptr)
                pq.push(ptr);
        }
        while(!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            if (cur->next->next)
                pq.push(cur->next->next);
            cur = cur->next;
        }
        return head->next;
    }
};//o(nlogk) 