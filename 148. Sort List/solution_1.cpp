/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//快排交换元素值写法
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)  return nullptr;
        quickSort(head, NULL);
        return head;
    }
    void quickSort(ListNode *start, ListNode *end) {    //范围[start, end)
        if (start->next == end) 
            return;
        ListNode *idx = partition(start, end);
	    if (idx > start)
            quickSort(start, idx);
        if ((!end && idx->next) || end > idx->next)
	        quickSort(idx->next, end);
    }
    ListNode *partition(ListNode *start, ListNode *end) {
        ListNode *pivot = RandomPivot(getLen(start, end), start);   //将pivot置于首位
        swap(start, pivot);
        ListNode *ptr = start, *idx = start->next;
        while (idx != end) {
            if (idx->val < start->val) {
                ptr = ptr->next;
                swap(idx, ptr);
            }
            idx = idx->next;
        }
        swap(start, ptr);
        return ptr;
    }
    void swap(ListNode *node1, ListNode *node2) {
    	int tmp = node2->val;
	    node2->val = node1->val;
	    node1->val = tmp;
    }
    int getLen(ListNode* start, ListNode *end) {
        ListNode *ptr = start;
        int len = 0;
        while (ptr != end) {
            ++ len;
            ptr = ptr->next;
        }
        return len;
    }
    ListNode* RandomPivot(int len, ListNode *head) {
        srand(time(NULL));
        int ran = rand() % len;
        ListNode *ptr = head;
        while (ran -- > 0)
            ptr = ptr->next;
        return ptr;
    }
};