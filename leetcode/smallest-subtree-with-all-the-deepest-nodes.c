/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int calcularAltura(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    

    int alturaEsq = calcularAltura(root->left);
    int alturaDir = calcularAltura(root->right);

    if(alturaEsq > alturaDir){
        return alturaEsq + 1;
    } else {
        return alturaDir + 1;
    }

}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    struct TreeNode* subarvore = root;
    int altura = calcularAltura(root) - 1;
    printf("Altura :%d\n",altura);
    int distanciaPercorrida = 0;
    
    //primeiro calcular a altura
    //depois varrer ate a altura
    // retornar a raiz
    // como calcular a altura?

    if(altura == 0){
        return root;
    }
    while(root->left != NULL){
        return subtreeWithAllDeepest(subarvore->left);
        distanciaPercorrida++;
    }
    while(root->right != NULL){
        return subtreeWithAllDeepest(subarvore->right);
        distanciaPercorrida++;
    }
    if(subarvore->right == NULL && subarvore->left == NULL && distanciaPercorrida != altura){
        return subtreeWithAllDeepest(root->right);
    } else {
        return root;
    }


    /*while(root->left != NULL){
        return subtreeWithAllDeepest(root->left);
        distanciaPercorrida++;
    }
    while(root->right != NULL){
        return subtreeWithAllDeepest(root->right);
        distanciaPercorrida++;
    }
    printf("Distancia percorrida: %d",distanciaPercorrida);
    if(distanciaPercorrida == altura){   
    return root;
    } else {
        printf("deu ruim\n");
        return root;
    }*/
}
