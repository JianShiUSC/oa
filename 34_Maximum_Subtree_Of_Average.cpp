struct Node {
    int val;
    vector<Node*> children;
    Node(int v) {
        val = v;
    }
};
class SumCount {
public:
    int sum;    // 当前总和
    int count;  // 总人数
    SumCount(int sum, int count) {
        this->sum = sum;
        this->count = count;
    }
};

class Company_Tree {
public:
    double resAve = INT_MIN;
    Node* result;

    SumCount* dfs(Node*& root) {
        if(root->children.empty()) {
            return new SumCount(root->val, 1);
        }

        int curSum = root->val;
        int curCount = 1;

        for(Node* child : root->children) {
            SumCount* sc = dfs(child);
            curSum += sc->sum;
            curCount += sc->count;
        }
        double curAve = (double)curSum/curCount;

        if(resAve < curAve) {
            resAve = curAve;
            result = root;
        }
        return new SumCount(curSum, curCount);
    }
    Node* getHighAve(Node* root) {
        if(!root) return NULL;
        dfs(root);
        return result;
    }
};

int main() {
    Node* root = new Node(1);
    Node* l21 = new Node(2);
    Node* l22 = new Node(3);
    Node* l23 = new Node(4);
    Node* l31 = new Node(5);
    Node* l32 = new Node(5);
    Node* l33 = new Node(5);
    Node* l34 = new Node(5);
    Node* l35 = new Node(5);
    Node* l36 = new Node(5);

    l21->children.push_back(l31);
    l21->children.push_back(l32);

    l22->children.push_back(l33);
    l22->children.push_back(l34);

    l23->children.push_back(l35);
    l23->children.push_back(l36);

    root->children.push_back(l21);
    root->children.push_back(l22);
    root->children.push_back(l23);
    Company_Tree sol;
    Node* res = sol.getHighAve(root);
    cout << res->val << endl;
    cout << sol.resAve << endl;
}
