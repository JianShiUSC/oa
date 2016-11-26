// leetcode 21
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* super = new ListNode(0);
        ListNode* cursor = super;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cursor->next = l1;
                l1 = l1->next;
            } else {
                cursor->next = l2;
                l2 = l2->next;
            }
            cursor = cursor->next;
        }
        if(l1) cursor->next = l1;
        if(l2) cursor->next = l2;
        return super->next;
    }
};
