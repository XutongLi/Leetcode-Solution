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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s;
        for (int g : G)
            s.insert(g);
        int cnt = 0;
        bool flag = false;
        ListNode* p = head;
        while (p != NULL) {
            if (s.find(p->val) != s.end()) {
                if (!flag) {
                    cnt ++;
                    flag = true;
                }
            }
            else
                flag = false;
            p = p->next;
        }
        return cnt;
    }
};