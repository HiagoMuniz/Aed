/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int qtd = 0, nodeRem = 0;
    struct ListNode* testQtd = head;
    struct ListNode* rem = head;
    struct ListNode* remAnt = NULL;

    if (head == NULL ){
        return NULL;
    }

    while (testQtd != NULL){
        qtd += 1;
        testQtd = testQtd->next;
    }

    if (n > qtd){
        return head;
    }


    nodeRem = qtd - n ;
    qtd = 0;

    if (nodeRem == 0) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    
    while (qtd != nodeRem){
        remAnt = rem;
        rem = rem->next;
        qtd++;
    }

    if ( remAnt != NULL ){
        remAnt->next = rem->next;
    }

    free(rem);

    return head;
}