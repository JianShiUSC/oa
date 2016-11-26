/*
2->1->3->4->5->6->7->8 变成 2->1->3->4->8->7->6->5；
如果总是为奇数，中间的也要变 5->7->8->6->3->4->2 变成 5->7->8->2->4->3->6 。
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x) {}
};

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // reverse second half of the list
    ListNode* pre = slow->next;
    ListNode* cur = pre->next;

    while(cur) {
        pre->next = cur->next;
        cur->next = slow->next;
        slow->next = cur;
        cur = pre->next;
    }
    return head;
}


int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    ListNode* l7 = new ListNode(7);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;

    reverseList(l1);
}
