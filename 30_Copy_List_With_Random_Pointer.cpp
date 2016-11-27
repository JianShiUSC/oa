// leetcode 138
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mm;
        RandomListNode* first = head;
        RandomListNode* second = new RandomListNode(first->label);
        mm[first] = second;

        while(first) {
            if(first->next) {
                if(mm.find(first->next) != mm.end()) {
                    second->next = mm[first->next];
                } else {
                    second->next = new RandomListNode(first->next->label);
                    mm[first->next] = second->next;
                }
            }
            if(first->random) {
                if(mm.find(first->random) != mm.end()) {
                    second->random = mm[first->random];
                } else {
                    second->random = new RandomListNode(first->random->label);
                    mm[first->random] = second->random;
                }
            }
            first = first->next;
            second = second->next;
        }
        return mm[head];
    }
};
