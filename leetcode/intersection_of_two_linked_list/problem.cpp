class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        unordered_set<ListNode*> s;
        while (ptrA != nullptr) {
            s.insert(ptrA);
            
            ptrA = ptrA->next;
        }
        
        while (ptrB != nullptr) {
            unordered_set<ListNode*>::const_iterator got = s.find (ptrB);

            if (got != s.end()) {
                return ptrB;
            }
            
            ptrB = ptrB->next;
        }
        
        return nullptr;
    }
};
