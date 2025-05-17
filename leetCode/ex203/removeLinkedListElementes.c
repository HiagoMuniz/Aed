/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL){
        return head;
    }
    while ( head != NULL && head->val == val ){
        head = head->next;
    }

    if (head == NULL) {
        return NULL;
    }

    struct ListNode *inicio = head->next;
    struct ListNode *antes = head;
    struct ListNode *lixo = NULL;

    while (inicio != NULL){
        if (inicio->val == val){
            lixo = inicio;
            antes->next = inicio->next;
            inicio = inicio->next;
            free(lixo);

        }else{
            antes = inicio;
            inicio = inicio->next;
        }
    }

    return head;
}