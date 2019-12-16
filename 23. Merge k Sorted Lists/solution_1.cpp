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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        if (lists.size() == 1)  return lists[0];
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        ListNode *mini = findMin(lists);
        while(mini != nullptr) {
            cur->next = mini;
            cur = cur->next;
            mini = findMin(lists);
        }
        return head->next;
    }
    ListNode *findMin(vector<ListNode*> &lists) {
        int mini = INT_MAX;
        int idx = -1;
        for (int i = 0; i < lists.size(); ++ i) {
            if (!lists[i])  
                continue;
            if (lists[i]->val < mini) {
                mini = lists[i]->val;
                idx = i;
            }
        }
        if (idx == -1)
            return nullptr;
        ListNode *res = lists[idx];
        lists[idx] = lists[idx]->next;
        return res;
    }
};//o(nk) n-all num 