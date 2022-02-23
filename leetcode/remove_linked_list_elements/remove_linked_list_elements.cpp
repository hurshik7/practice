
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        ListNode* ptr = head;
        ListNode* prevNode = ptr;
        bool isDeleted = false;
        while (ptr != nullptr) {
            isDeleted = false;
            if (ptr->val == val) {
                ListNode* temp = ptr;
                prevNode->next = ptr->next;
                isDeleted = true;
                delete temp;
            }
            
            if (isDeleted == true) {
                ptr = prevNode->next;   
            } else {
                prevNode = ptr;
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};
