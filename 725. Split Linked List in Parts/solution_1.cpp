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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int len = 0;
        ListNode *p = root;
        while (p) {
            p = p->next;
            ++ len;
        }
        p = root;
        ListNode *pre = nullptr;
        while (k > 0 && p) {
            int sz = len / k + (len % k > 0 ? 1 : 0);
            len -= sz;
            while (sz --) {
                pre = p;
                p = p->next;
            }
            pre->next = nullptr;
            res.push_back(root);
            root = p;
            -- k;
        }
        while (k > 0) {
            res.push_back(nullptr);
            -- k;
        }
        return res;
    }
};
//time O(n)