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




// no global variable
class TreeNode {
public:
    int val;
    vector<TreeNode*> children;
    TreeNode(int v) {
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

class CompanyTree {
public:
    SumCount* dfs(TreeNode*& root, double& resAve, TreeNode*& result) {
        if(root->children.empty()) {
            return new SumCount(root->val, 1);
        }

        int curSum = root->val;
        int curCount = 1;

        for(TreeNode* child : root->children) {
            SumCount* sc = dfs(child, resAve, result);
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

    TreeNode* getHighAve(TreeNode* root) {
        if(!root || root->children.empty()) return NULL;
        TreeNode* result = root;
        double resAve = INT_MIN;
        dfs(root, resAve, result);
        return result;
    }
};

int main() {
//    TreeNode* root = new TreeNode(1);
//    TreeNode* l21 = new TreeNode(3);
//    TreeNode* l22 = new TreeNode(4);
//    TreeNode* l23 = new TreeNode(6);
//
//    TreeNode* l31 = new TreeNode(2);
//    TreeNode* l32 = new TreeNode(8);
//    TreeNode* l33 = new TreeNode(7);
//
//    TreeNode* l34 = new TreeNode(4);
//    TreeNode* l35 = new TreeNode(0);
//    TreeNode* l36 = new TreeNode(6);
//
//    TreeNode* l37 = new TreeNode(0);
//    TreeNode* l38 = new TreeNode(2);
//    TreeNode* l39 = new TreeNode(9);
//
//    l21->children.push_back(l31);
//    l21->children.push_back(l32);
//    l21->children.push_back(l33);
//
//    l22->children.push_back(l34);
//    l22->children.push_back(l35);
//    l22->children.push_back(l36);
//
//    l23->children.push_back(l37);
//    l23->children.push_back(l38);
//    l23->children.push_back(l39);
//
//    root->children.push_back(l21);
//    root->children.push_back(l22);
//    root->children.push_back(l23);
//    CompanyTree sol;
//    TreeNode* res = sol.getHighAve(root);
//    cout << res->val << endl;

    TreeNode* root = new TreeNode(10);
    TreeNode* p1 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(5);
    TreeNode* p3 = new TreeNode(6);

    TreeNode* p11 = new TreeNode(5);
    TreeNode* p12 = new TreeNode(5);
    TreeNode* p21 = new TreeNode(5);
    TreeNode* p22 = new TreeNode(5);
    TreeNode* p31 = new TreeNode(5);
    TreeNode* p32 = new TreeNode(5);

    p1->children.push_back(p11);
    p1->children.push_back(p12);

    p2->children.push_back(p21);
    p2->children.push_back(p22);

    p3->children.push_back(p31);
    p3->children.push_back(p32);


    root->children.push_back(p1);
    root->children.push_back(p2);
    root->children.push_back(p3);

    CompanyTree sol;
    TreeNode* res = sol.getHighAve(root);
    cout << res->val << endl;
}
