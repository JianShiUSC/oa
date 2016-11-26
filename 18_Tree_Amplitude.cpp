struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int minV, int maxV) {
    if(!root) return maxV - minV;
    if(root->val < minV) minV = root->val;
    if(root->val > maxV) maxV = root->val;
    return max(helper(root->left, minV, maxV), helper(root->right, minV, maxV));
}

int solution(TreeNode* root) {
    if(!root) return 0;
    return helper(root, root->val, root->val);
}
