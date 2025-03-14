/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* encontrarMeio(struct ListNode* head){
    struct ListNode* lento = head;
    struct ListNode* rapido = head->next;

    while(rapido != NULL && rapido->next != NULL){
        lento = lento->next;
        rapido = rapido->next->next;
    }

    return lento;
}

struct ListNode* merge(struct ListNode* a, struct ListNode* b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }

    struct ListNode* resultado = NULL;

    if(a->val <= b->val){
        resultado = a;
        resultado->next = merge(a->next,b);
    } else {
        resultado = b;
        resultado->next = merge(a,b->next);
    }

    return resultado;


}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* meio = encontrarMeio(head);

    struct ListNode* a = head;
    struct ListNode* b = meio->next;
    meio->next = NULL;

    a = sortList(a);
    b = sortList(b);

    return merge(a,b);


}
