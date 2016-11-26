struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solution(TreeNode* root) {
    if(!root) return 0;
    if(root->left && !root->right) return solution(root->left) + root->val;
    if(!root->left && root->right) return solution(root->right) + root->val;
    return min(solution(root->left), solution(root->right)) + root->val;
}
