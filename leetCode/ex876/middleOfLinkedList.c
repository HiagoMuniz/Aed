/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int i = 1;

    struct ListNode* count = head;

    while (count->next != NULL){
        count = count->next;
        i++;
    }

    while ( fast->next != NULL && fast->next->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if ( i % 2 == 0){
        slow = slow->next;
        return slow;
    }else{
        return slow;
    }

}