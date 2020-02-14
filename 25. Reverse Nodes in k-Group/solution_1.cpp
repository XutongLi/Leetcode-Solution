/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
ListNode* reverse(ListNode *beg, ListNode *end, ListNode *pre) {    //翻转[beg, end)
    ListNode *beg_copy = beg;
    ListNode *fast = beg->next;
    while (fast != end) {
        ListNode *tmp = fast->next;
        fast->next = beg;
        beg = fast;
        fast = tmp;
    }
    beg_copy->next = end;
    pre->next = beg;
    return beg_copy;    //返回值作为下一次翻转的pre（即beg的前一个元素）
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) 
            return head;
        ListNode *fake = new ListNode(-1);
        fake->next = head;
        ListNode *beg = head, *end = head, *pre = fake;
        int cnt = 0;
        while (end) {
            end = end->next;
            ++ cnt;
            if (cnt % k == 0) {
                pre = reverse(beg, end, pre);
                beg = end;
            }
        }
        return fake->next;
    }
};
//time O(n)  space O(1)