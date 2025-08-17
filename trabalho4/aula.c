/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct ListNode node;
void sort(node* head);
node* sortList(node* head) {

    if ( head == NULL){
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while ( fast->next  != NULL && fast->next->next != NULL  ){
    slow = slow->next; // slow igual ao mexio da minha lista
    fast = fast->next->next;
    }

    if ( fast->next != NULL ){
        fast = fast->next;
    }
    printf("%d\n", slow->val);
    printf("%d\n", fast->val);

    
    node* cabeca = head;
    sort(slow->next);
    node* lento = slow;
    lento->next = NULL;
    sort(cabeca);

    return head;
}


void sort(node* head){

    if ( head->next == NULL){
        return;
    }

    if ( head->next->next == NULL ){
        if ( head->val < head->next->val){
            return;
        }else{
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
            return;
        }
    }

    node* slow = head;
    node* fast = head;
    while ( fast->next  != NULL && fast->next->next != NULL  ){
        slow = slow->next; // slow igual ao meio da minha lista
        fast = fast->next->next;
    }
        
    if ( fast->next != NULL ){
        fast = fast->next;
    }

    printf("%d\n", slow->val);
    printf("%d\n", fast->val);

    node* lento = slow;
    lento->next = NULL;
    sort(head);
}

// eu sei que eu tenho que ficar dividindo a minha lista ate eu ter apenas dois elementos, ai eu comparo eles troco, igual a um mergesort, mas a implementação nao estou conseguindo fazer

// pode ser um ponteiro rapido e um lento

// vou ate o meio pego a direita e a esquerda

// head->next->next->val == slow->val && slow != NULL && head->nex != NULL  && head->next->next != NULL
/*
    while ( fast->next  != NULL && fast->next->next != NULL  ){
        slow = slow->next; // slow igual ao meio da minha lista
        fast = slow->next;

        sort
    }
*/