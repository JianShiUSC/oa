/*
插入一个新的节点到一个sorted cycle linkedlist（升序），返回新的节点。给的list节点不一定是最小节点。
所以先要找到最小的点，或者可能需要找到最大的节点。如果给的节点比最小的数还要小，那么需要插入在最大的节点后面。
所以需要考虑两种情况：1，正常插入在两个节点中间；2，插入在最大最小即排序起始处。
注意：可能list中含有duplicate！！！
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x) {}
};


ListNode* solution(ListNode* head, int val) {
    if(!head) {
        ListNode* newNode = new ListNode(val);
        newNode->next = newNode;
        return newNode;
    }

    ListNode* cur = head;

    do {
        if(val <= cur->next->val && val >= cur->val) break;
        if(cur->val > cur->next->val && (val < cur->next->val || val > cur->val)) break;
        cur = cur->next;
    } while (cur != head);

    ListNode* newNode = new ListNode(val);
    newNode->next = cur->next;
    cur->next = newNode;
    return newNode;
}

int main() {
    ListNode* head = new ListNode(10);
    head->next = head;
    solution(head, 11);
}
