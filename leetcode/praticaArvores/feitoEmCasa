/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int somarEsquerda(struct TreeNode* root){
    if(root == NULL){
    return 0;
    }
    if(root->left == NULL && root->right == NULL){
    return root->val;
    }
    return 0;    
}


int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }

    int somaEsq = sumOfLeftLeaves(root->left) + somarEsquerda(root->left);
    int somaDir = sumOfLeftLeaves(root->right);
    printf("soma Esq: %d soma Dir: %d\n",somaEsq,somaDir);
    return somaEsq + somaDir;
}
