/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
node* sort(node* head);
node* mergeLists(node* a, node* b);


node* sortList(node* head) {
    return sort(head);
}

node* sort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    if (head->next->next == NULL) {
        if (head->val > head->next->val) {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
        }
        return head;
    }

    node* slow = head;
    node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* secondHalf = slow->next;
    slow->next = NULL;

    node* left = sort(head);
    node* right = sort(secondHalf);

    return mergeLists(left, right);
}


node* mergeLists(node* a, node* b) {

    if (a == NULL) return b;
    if (b == NULL) return a;

    node* head = NULL;
    node* current = NULL; 

    if (a->val <= b->val) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
    current = head;

    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            current->next = a; 
            a = a->next;       
        } else {
            current->next = b;
            b = b->next;       
        }
        current = current->next;
    }

    if (a != NULL) {
        current->next = a;
    } else {
        current->next = b;
    }

    return head;
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