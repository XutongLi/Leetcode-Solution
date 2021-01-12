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
    TreeNode *build(ListNode *&head, int l, int r) {    //head必须为指针的引用（不可使用拷贝的指针，因为head递归过程中连续右移）
        if (l > r)  //l r用来判断何时为空
            return nullptr;
        int mid = (r - l) / 2 + l;
        TreeNode *left = build(head, l, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = build(head, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode *p = head;
        while (p != nullptr) {
            ++ len;
            p = p->next;
        }
        return build(head, 0, len - 1);
    }
};
//通过中序遍历结果构建平衡二叉树
//O(n)