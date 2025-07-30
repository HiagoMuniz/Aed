/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 typedef struct TreeNode node;

void dfs( node* root, int* soma);
//int sumLeft (node* head, int soma);

node* convertBST(node* root) {
    int soma = 0;
    dfs(root, &soma);

    return root;

}

void dfs( node* root, int *soma){
    if ( root == NULL )
        return;

    dfs(root->right, soma);

    root->val += *soma;
    *soma = root->val;

    dfs(root->left, soma);
}


/*
int sumLeft (node* head, int soma){
    if (head == NULL)
        return soma;

    soma += head->val;

    sumLeft(head->left, soma);
    sumLeft(head->right, soma);

    return soma;
}
*/