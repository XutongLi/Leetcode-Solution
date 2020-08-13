/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode *reverseList(ListNode *cur, ListNode *pre) {
        if (!cur)   return pre;
        ListNode *next = cur->next;
        cur->next = pre;
        return reverseList(next, cur);
        
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverseList(head, nullptr);
    }
};