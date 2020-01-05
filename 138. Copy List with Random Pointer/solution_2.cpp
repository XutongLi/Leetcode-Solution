/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        if (mp[head])   return mp[head];
        mp[head] = new Node(head->val);
        mp[head]->next = copyRandomList(head->next);
        mp[head]->random = copyRandomList(head->random);
        return mp[head];
    }
};