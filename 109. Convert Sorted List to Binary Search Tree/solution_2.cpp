/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *build(const vector<int> &vec, int l, int r) {
        if (l > r)
            return nullptr;
        int mid = (r - l) / 2 + l;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = build(vec, l, mid - 1);
        root->right = build(vec, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while (head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }
        return build(vec, 0, vec.size() - 1);
    }
};
//O(n) 先转化成数组