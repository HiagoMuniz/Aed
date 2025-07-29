/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;
int height(node* root);

bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}


int height(node* root){
    if ( root == NULL ){
        return 0;
    }

    int left = height(root->left);
    if ( left == -1) return -1;

    int right = height(root->right);
    if ( right == -1) return -1;

    if (left - right > 1 || left - right < -1)
        return -1;

    return 1 + (left > right ? left : right);
}