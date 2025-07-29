/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 typedef struct TreeNode tree;
void dfs(int *vector, tree *root, int *size);

int* preorderTraversal(tree* root, int* returnSize) {
    *returnSize = 0;
    int *vec = malloc(sizeof(int) * 200);
    dfs(vec, root, returnSize);

    return vec;
}

void dfs(int *vec, tree *root, int *size){

    if (!root){
        return;
    }

    vec[(*size)++] = root->val;

    dfs(vec, root->left, size);
    dfs(vec, root->right, size);
}
