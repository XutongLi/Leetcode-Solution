class MyLinkedList {
    class ListNode{
        int val;
        ListNode next;
        ListNode(int val)
        {
            this.val = val;
            next = null;
        }
    }

    ListNode head;
    int len;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        len = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index >=0 && index < len) {
            ListNode ptr = head;
            for (int i = 0; i < index; i++) {
                ptr = ptr.next;
            }
            return ptr.val;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        ListNode temp = new ListNode(val);
        temp.next = head;
        head = temp;
        len ++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        ListNode ptr = head;
        while (ptr.next != null) {
            ptr = ptr.next;
        }
        ptr.next = new ListNode(val);
        len ++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index <= len) {
            ListNode forward = new ListNode(-1);
            forward.next = head;
            ListNode ptr = forward;
            int i = 0;
            while (i < index) {
                ptr = ptr.next;
                i ++;
            }
            ListNode addNode = new ListNode(val);
            addNode.next = ptr.next;
            ptr.next = addNode;
            len ++;
            head = forward.next;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < len) {
            ListNode forward = new ListNode(-1);
            forward.next = head;
            ListNode ptr = forward;
            int i = 0;
            for (i = 0; i < index; i++) {
                ptr = ptr.next;

            }
            ptr.next = ptr.next.next;
            len --;
            head = forward.next;
        }
    }

}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
