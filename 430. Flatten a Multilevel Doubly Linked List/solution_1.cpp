/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
private:
    Node *dfs(Node* head) {
        if (!head)  return nullptr;
        if (!head->next && !head->child)  return head;
        auto next = head->next;
        if (head->child) {
            head->next = head->child;
            head->child->prev = head;
            auto back = dfs(head->child);
            if (back)   back->next = next;
            if (next)   next->prev = back;
            head->child = nullptr;
        }
        return dfs(next);   //返回从head节点开始一直遍历到的没有next与child的节点
    }
public:
    Node* flatten(Node* head) {
        if (!head)  return nullptr;
        dfs(head);
        return head;
    }
};
//DFS