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
        vector<ListNode*> res(k);
        int len = 0;
        ListNode *p = root;
        while (p) {
            p = p->next;
            ++ len;
        }
        int sz = len / k, rem = len % k;
        for (int i = 0; i < k && root; ++ i) {
            res[i] = root;
            for (int j = 1; j < sz + (i < rem); ++ j)
                root = root->next;
            ListNode *tmp = root->next;
            root->next = nullptr;
            root = tmp;
        }
        return res;
    }
};
//time O(n)