// 检查T2是否是T1的子树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2) return true;
    if(!t1 || !t2) return false;
    if(t1->val != t2->val) return false;
    return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

bool isSubTree(TreeNode* t1, TreeNode* t2) {
    if(!t2) return true;
    if(!t1) return false;
    return isSameTree(t1, t2) || isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
}
