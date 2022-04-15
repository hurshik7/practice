/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* ptrArr[10000] = {NULL, };
    size_t count = 0;
    struct ListNode* ptr = head;
    
    while (ptr != NULL) {
        for (size_t i = 0; i < count; i++) {
            if (ptr == ptrArr[i]) {
                return ptr;
            }
        }    
        ptrArr[count++] = ptr; 
        ptr = ptr->next;
    }
    
    return NULL;
}
