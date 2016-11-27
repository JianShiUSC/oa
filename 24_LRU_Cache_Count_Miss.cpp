// 实现 LRU Cache再判断啥时候miss就好了，返回miss数。
class LRUCache {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v) {}
    };

    int maxSize;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> keyToNode;

    void insertToEnd(int v) {
        Node* nd = new Node(v);
        keyToNode[v] = nd;
        if(!head) {
            head = tail = nd;
        } else {
            tail->next = nd;
            nd->prev = tail;
            tail = tail->next;
        }
    }

    void removeHead() {
        if(!head) return;
        keyToNode.erase(head->val);
        if(head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
    }

    void moveToEnd(int v) {
        if(keyToNode.count(v) == 0 || keyToNode[v] == tail) return;
        Node* nd = keyToNode[v];
        if(nd == head) {
            head = head->next;
            head->prev = NULL;
        } else {
            nd->prev->next = nd->next;
            nd->next->prev = nd->prev;
        }
        tail->next = nd;
        nd->prev = tail;
        nd->next = NULL;
        tail = tail->next;
    }

    bool isFull() {
        return keyToNode.size() >= maxSize;
    }

public:
    LRUCache(int capacity) {
        maxSize = capacity;
        head = NULL;
        tail = NULL;
        keyToNode.clear();
    }

    int solution(vector<int> arr) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(keyToNode.find(arr[i]) != keyToNode.end()) {
                moveToEnd(arr[i]);
            } else {
                count++;
                if(isFull()) {
                    removeHead();
                }
                insertToEnd(arr[i]);
            }
        }
        return count;
    }
};


int main() {
    vector<int> arr = {1,2,3,2,2,2,3};
    LRUCache ins(2);
    cout << ins.solution(arr) << endl;
}
